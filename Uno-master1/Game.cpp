//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Game.h"




Game::Game(){
}

void Game::readFile() {
  Card card(0,"blank");
  std::vector<Card> cards;
  Deck deck(0,cards);
  int numCards;
  int value;
  std::string color;
  std::ifstream file("C:/Users/T PC/Desktop/Midterm 2_ Uno Starter Code/Configs/Decks/Regular.txt");
  std::string line;
  while (getline(file, line)) {
    file >> std::ws;
    std::stringstream ss;
    ss << line;
    //card = nullptr;
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
  playGame();
//    std::cout << "All the Cards in the file: ---------------------------------------------------------------------------" << std::endl;
//    for (int i = 0; i < deck.getDeck().size(); i++) {
//        std::cout << deck.getDeck().at(i).getColor() << " "
//                  << deck.getDeck().at(i).getValue()  << std::endl;
//    }
//    std::cout<<"The deck is before anything:"<<deck.getDeck().size();
  //return deck.getDeck();
}


void Game::playGame() {
  //std::vector<Card> playingDeck = deck.getDeck();
//  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
//  std::shuffle(deck.begin(), deck.end(), generator);
  std::vector<Card> playerHand;
  std::vector<Card> discardedCards;
  //std::vector<Player> players;
  Player player(" ", 0, playerHand);
  int numPlayers;
  std::string playerName;
  auto discard = DiscardPile(discardedCards);
  std::cout << "Enter the number of players you want: ";
  std::cin >> numPlayers;
  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Player " << i + 1 << " enter your name: ";
    std::cin >> playerName;
    player =  Player(playerName, 0, playerHand);
    aPlayers.push_back(player);
  }
  std::cin.ignore();
  std::cout << "Player Hands: ------------------------------------------------------------------------------------------" << std::endl;
  for (int i = 0; i < aPlayers.size(); i++) {
    for (int j = 0; j < 7; j++) {
      playerHand.push_back(aDeck.at(j));
    }
    aDeck.erase(aDeck.begin(), aDeck.begin() + 7);
    aPlayers.at(i).setPlayerHand(playerHand);
    playerHand.erase(playerHand.begin(), playerHand.begin() + 7);
  }
  for ( int i = 0; i < 1 ; i++){
    discardedCards.push_back(aDeck.at(i));
    aDeck.erase(aDeck.begin(),aDeck.begin()+1);
    discard.setDiscardPile(discardedCards);
    discardedCards.erase(discardedCards.begin(),discardedCards.begin()+1);
  }



//Prints out all players Hands
  for (int i = 0; i < aPlayers.size(); i++) {
    std::cout << aPlayers.at(i).getPlayerName() << ": ";
    for (const auto& j : aPlayers.at(i).getHand()) {
      std::cout << j.getColor() << " " << j.getValue() << ", ";
    }
    std::cout << "\n";
  }



  std::string playerResponse;
  //Move playerMove(playerResponse);

    for (int i = 0; i < aPlayers.size(); i++) {
      std::cout << "Top card is: " << discard.getDiscardPile().at(0).getColor() << " " << discard.getDiscardPile().at(0).getValue() << std::endl;
      for (int j = 0; j < 5; j++) {
        playCard(aPlayers.at(i));
//        std::cout << aPlayers.at(i).getPlayerName() << " what would you like to do? ";
//        std::getline(std::cin, playerResponse);
//
//        aPlayers.at(i) = Move(playerResponse).moveType(aPlayers.at(i));

      }
      for (int i = 0; i < aDiscardPile.size(); i ++){
        std::cout << aDiscardPile.at(i).getColor() << " " << aDiscardPile.at(i).getValue() << std::endl;
      }
    }

}

void Game::playCard(Player& player) {
  std::string requestedCard;
  Card cardVersion(0, "Blank");
  std::string color;
  int value;
  bool cardExists = false;
  while (cardExists == false) {
    std::cout << player.getPlayerName() << ": What card do you want?: ";
    std::getline(std::cin, requestedCard);
    std::stringstream ss(requestedCard);
    while (ss >> color >> value) {
      cardVersion = Card(value, color);
    }
    auto cardToRemove = std::find(player.getHand().begin(), player.getHand().end(), cardVersion);
    if(cardToRemove != player.getHand().end()){
      aDiscardPile.push_back(*cardToRemove);
      player.getHand().erase(cardToRemove);
      cardExists = true;
    }
    else {
      std::cout << "Your card is invalid." << std::endl;
    }
  }

}