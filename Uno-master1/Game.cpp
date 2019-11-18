//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Game.h"




Game::Game(){
}

void Game::readFile(std::string fileName, std::string rulesFile, std::string seed) {
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
  allExistingCards = deck.getDeck();
  Rules rules;
  rules.readfile(rulesFile);
  setRules(rules);


  playGame(seed);
}

void Game::setRules(Rules rules){
  aRules = rules;
}
bool Game::endGame(std::vector<Card>& playerHands){
  if(playerHands.size() == 0){
    return true;
  }
  else{
    return false;
  }
}

void Game::playGame(std::string seed) {
  if(seed.empty()){
    std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(aDeck.begin(), aDeck.end(), generator);
  }
  else {
  std::minstd_rand generator(stoi(seed));
  std::shuffle(aDeck.begin(), aDeck.end(), generator);
  }
  for (int i = 0; i < aDeck.size(); i++) {
    std::cout << aDeck.at(i).getColor() << " "
              << aDeck.at(i).getValue()  << std::endl;
  }
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
  std::cout << "\n";
  std::cin.ignore();
int j = 0;
while(j  < aRules.startingHandSize()){
  for (int i = 0; i < aPlayers.size(); i++) {
    //playerHand.push_back(aDeck.at(j));
    aPlayers.at(i).setPlayerHand(aDeck.at(aDeck.size()-1));

    aDeck.erase(aDeck.end() - 1, aDeck.end());
    //playerHand.clear();
    std::sort(aPlayers.at(i).getHand().begin(), aPlayers.at(i).getHand().end());
  }
  j++;
}



  for (int i = 0; i < 1; i++) {
    discardedCards.push_back(aDeck.at(i));
    aDiscardPile.push_back(aDeck.at(i));
    aDeck.erase(aDeck.begin(), aDeck.begin() + 1);
    discard.setDiscardPile(discardedCards);
    discardedCards.erase(discardedCards.begin(), discardedCards.begin() + 1);
    aDrawPile = aDeck;
  }
  bool cardExists;


bool endOfGame = false;
  while(endOfGame == false) {
    for (int i = 0; i < aPlayers.size(); i++) {
      cardExists = false;
      int drawLimit = 0;
      while (cardExists == false) {
        std::string playerResponse;
        std::string move = " ";
        std::string color = " ";
        std::string value =" ";
        Card card(0, "blank");
        std::string callout= " ";
        Move playerMove(move,color,value,callout);




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
          }


          playerMove = Move(move, color, value, callout);

          if (playerMove.moveType() == "play") {
            card = Card(stoi(value), color);
            cardExists = playCard(aPlayers.at(i), card);

          } else if (playerMove.moveType() == "draw") {
            if (drawLimit < aRules.drawLimit()) {
              draw(aPlayers.at(i));
              drawLimit++;
              cardExists = false;
            } else {
              std::cout << "You have already drawn the maximum number of cards this round." << std::endl;
            }
          } else if (playerMove.moveType() == "selfCallout") {
            playCard(aPlayers.at(i), card);
            cardExists = selfUnoCallout(aPlayers.at(i));
          } else if (playerMove.moveType() == "uno") {
            cardExists = unoCalledOn(color, aPlayers.at(i));
          } else if (playerMove.moveType() == "skip") {
            if (aRules.mustPlayCardEachTurn() == false) {
              cardExists = true;
            } else if (aRules.mustPlayCardEachTurn() == true) {
              std::cout << "You cannot pass. You must play a card this turn." << std::endl;
              cardExists = false;
            }
          } else if (playerMove.moveType() == "help") {
            std::cout << "- play card_color card_value [uno]\n"
                         "- draw\n"
                         "- uno player_name\n"
                         "- skip\n"
                         "- quit\n"
                         "- help" << std::endl;
            cardExists = false;
          }
          else if (playerMove.moveType() == "unknown"){
            std::cout << "Unknown command entered." << std::endl;
            cardExists = false;
          }


      }
      endOfGame = endGame(aPlayers.at(i).getHand());
    }

  }

  std::cout<< "==== Leader Board ====" << std::endl;
  for (int i = 0 ; i < aPlayers.size(); i++){
    std::cout << i <<".) " << aPlayers.at(i).getPlayerName()<<std::endl;
  }
}

bool Game::playCard(Player& player, const Card& card) {
  auto cardToRemove = std::find(player.getHand().begin(), player.getHand().end(), card);
  auto existingCard = std::find(allExistingCards.begin(), allExistingCards.end(), card);
    if(cardToRemove != player.getHand().end()){
      if((*cardToRemove).canPlay(aDiscardPile.at(aDiscardPile.size() - 1))) {
        std::cout << player.getPlayerName() << " played " << (*cardToRemove).getColor() << " "
                  << (*cardToRemove).getValue() << std::endl;
        aDiscardPile.push_back(*cardToRemove);
        player.getHand().erase(cardToRemove);
        return true;
      }
      else{
        std::cout << "You can't play this card. The color or numbers have to the be the same." << std::endl;
        return false;
      }
    }
    else if(cardToRemove == player.getHand().end() && existingCard != allExistingCards.end()) {
      std::cout << "You can't play a " << (*existingCard).getColor() << " " << (*existingCard).getValue() << " because your aren't holding one." << std::endl;
      return false;
    }

}

void Game::draw(Player& player) {
  if(aDrawPile.empty()){
    std::cout << "There are no cards left to draw. Please play a card." << std::endl;
  }
  else{
  player.getHand().push_back(aDrawPile.at(aDrawPile.size()-1));
  }
}



bool Game::unoCalledOn(std::string& playerName, Player& playerThatCalledUnoOnSomeone){
  for (int i = 0; i < aPlayers.size(); i++) {
    if (playerName == aPlayers.at(i).getPlayerName()) {


      if (aPlayers.at(i).getHand().size() > 1) {
        std::cout << "You can't call UNO on " << aPlayers.at(i).getPlayerName()
                  << " because they have more than 1 card in their hand" << std::endl;
        for (int j = 0; j < aRules.badUnoCalloutPenalty(); j++) {
          draw(playerThatCalledUnoOnSomeone);
          std::cout << "Hand values inside uno member: " << std::endl;
          for (int u = 0; u < playerThatCalledUnoOnSomeone.getHand().size(); u++) {

            std::cout << playerThatCalledUnoOnSomeone.getHand().at(u).getColor() << " "
                      << playerThatCalledUnoOnSomeone.getHand().at(u).getValue() << ", ";
          }
        }
        return false;
      }
      else {
        for (int j = 0; j < aRules.unoCallOutPenalty(); j++) {
          draw(aPlayers.at(i));
        }
        return true;
      }
    }
  }
}


bool Game::selfUnoCallout(Player& playerName) {
  if(playerName.getHand().size()<= 2) {
      return true;
  }
  else{
    for (int i = 0; i < aRules.unoCallOutPenalty(); i++) {
      draw(playerName);
    }
    std::cout<< "You can't call UNO unless playing your second to last card." << std::endl;
    return false;
  }
}
