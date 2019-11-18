//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Game.h"




Game::Game(){
}

void Game::readFile(std::string fileName,int seed) {
  Card card(0,"blank");
  std::vector<Card> cards;
  Deck deck(0,cards);
  int numCards;
  int value;
  std::string color;
  std::ifstream file(fileName);
  std::string line;
  while (getline(file, line)) {
    file >> std::ws;
    std::stringstream ss;
    ss << line;
    ss >> numCards;
    ss >> color;
    ss >> value;
    for (int i = 1; i <= numCards; i++) {
      card =  Card(value, color);
      cards.push_back(card);
      deck =  Deck(numCards, cards);
    }
  }
  aDeck = deck.getDeck();
  playGame(seed);
//    for (int i = 0; i < deck.getDeck().size(); i++) {
//        std::cout << deck.getDeck().at(i).getColor() << " "
//                  << deck.getDeck().at(i).getValue()  << std::endl;
//    }
}


void Game::playGame(int seed) {
  if(seed == NULL){
    std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(aDeck.begin(), aDeck.end(), generator);
  }
  std::minstd_rand generator(seed);
  std::shuffle(aDeck.begin(), aDeck.end(), generator);
  std::vector<Card> playerHand;
  std::vector<Card> discardedCards;
  Player player(" ", 0, playerHand);
  int numPlayers;
  std::string playerName;
  auto discard = DiscardPile(discardedCards);
  std::cout << "Enter the number of players in the game: ";
  std::cin >> numPlayers;
  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Player " << i + 1 << " enter your name: ";
    std::cin >> playerName;
    player = Player(playerName, 0, playerHand);
    aPlayers.push_back(player);
  }
  std::cin.ignore();
  for (int i = 0; i < aPlayers.size(); i++) {
    for (int j = 0; j < 7; j++) {
      playerHand.push_back(aDeck.at(j));
    }
    aDeck.erase(aDeck.begin(), aDeck.begin() + 7);
    aPlayers.at(i).setPlayerHand(playerHand);
    playerHand.erase(playerHand.begin(), playerHand.begin() + 7);
  }
  for (int i = 0; i < 1; i++) {
    discardedCards.push_back(aDeck.at(i));
    aDiscardPile.push_back(aDeck.at(i));
    aDeck.erase(aDeck.begin(), aDeck.begin() + 1);
    discard.setDiscardPile(discardedCards);
    discardedCards.erase(discardedCards.begin(), discardedCards.begin() + 1);
    aDrawPile = aDeck;
  }

  std::string playerResponse;
  Move playerMove(playerResponse);
  std::string move;
  std::string color;
  int value;
  Card card(0, "blank");
  bool cardExists;
  std::string callout;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < aPlayers.size(); i++) {
      cardExists = false;
      while (cardExists == false) {




        for (int x = 0; x < aPlayers.size(); x++){
          if(x!= i) {
            std::cout << aPlayers.at(x).getPlayerName() << ": ";
            for (int u = 0; u < aPlayers.at(x).getHand().size(); u++) {

              std::cout << aPlayers.at(x).getHand().at(u).getColor() << " "
                        << aPlayers.at(x).getHand().at(u).getValue() << ", ";
              if (u == aPlayers.at(x).getHand().size() - 1) {
                std::cout << "\n";
              }
            }
          }
        }



        std::cout << "Top of discard pile: " << aDiscardPile.at(aDiscardPile.size() - 1).getColor() << " "
                  << aDiscardPile.at(aDiscardPile.size() - 1).getValue() << std::endl;
        std::cout << "Your hand: ";
        for (int j = 0; j < aPlayers.at(i).getHand().size(); j++) {
          std::cout << aPlayers.at(i).getHand().at(j).getColor() << " " << aPlayers.at(i).getHand().at(j).getValue()
                    << ", ";
          if (j == aPlayers.at(i).getHand().size() - 1) {
            std::cout << "\n";
          }
        }
        std::cout << aPlayers.at(i).getPlayerName() << ", enter your move, or h for help: ";
        std::getline(std::cin, playerResponse);
        std::stringstream ss(playerResponse);
        while (ss >> move >> color >> value >> callout) {
          card = Card(value, color);
        }

        playerMove = Move(move);
        if (playerMove.moveType() == "play") {
          if(shortFormInput(color, "uno")){
            if(uno(aPlayers.at(i).getPlayerName())==false){
              std::cout << "You had to draw 3 cards for a bad UNO call." << std::endl;
            }
            else{
              std::cout << aPlayers.at(i).getPlayerName() << " shouted Uno" << std::endl;
            }
          }
          else if(shortFormInput(callout,"uno")){
            cardExists = playCard(aPlayers.at(i), card);
            if(uno(aPlayers.at(i).getPlayerName())==false){
              std::cout << "You had to draw 3 cards for a bad UNO call." << std::endl;
            }

          }
        }

        if (playerMove.moveType() == "draw") {
          draw(aPlayers.at(i));
          cardExists = true;
        }
        if (playerMove.moveType() == "uno"){
          if(uno(color) == false){
            draw(aPlayers.at(i));
            std::cout << "You can't call UNO on "<< color <<" because they have more than 1 card in their hand" << std::endl;
          }
          cardExists = true;
        }
        if (playerMove.moveType() == "skip"){
          break;
        }
        if(playerMove.moveType() == "help"){
          std::cout << "- play card_color card_value [uno]\n"
                       "- draw\n"
                       "- uno player_name\n"
                       "- skip\n"
                       "- quit\n"
                       "- help" << std::endl;
        }

      }
    }

  }
}

bool Game::playCard(Player& player, Card card) {
  bool cardExists = false;
    auto cardToRemove = std::find(player.getHand().begin(), player.getHand().end(), card);
    if(cardToRemove != player.getHand().end() && (*cardToRemove).canPlay(aDiscardPile.at(aDiscardPile.size() - 1))){
      std::cout << player.getPlayerName() << " played " << (*cardToRemove).getColor() << " " << (*cardToRemove).getValue() << std::endl;
      aDiscardPile.push_back(*cardToRemove);
      player.getHand().erase(cardToRemove);
      return  true;
    }
    else {
      std::cout << "You can't play a " << card.getColor() << " " << card.getValue() << " because your aren't holding one." << std::endl;
      return false;
    }

}

void Game::draw(Player& player) {
  player.getHand().push_back(aDrawPile.at(0));
}



bool Game::uno(std::string playerName){
  for(int i = 0; i < aPlayers.size(); i++){
    if (playerName == aPlayers.at(i).getPlayerName()){
      Player calledOutPlayer = aPlayers.at(i);
    }
    if(aPlayers.at(i).getHand().size()>1) {
      return false;
    }
  }

}