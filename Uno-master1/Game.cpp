//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Game.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>


//Reads through the file and store the cards into a deck
void readFile() {
  Deck* deck;
  std::vector<Card*> playingDeck;
  std::vector<Deck*> numAndTypeStorage;
  Card* card;
  int numCards;
  int value;
  std::string color;
  std::ifstream file("C:/Users/T PC/Desktop/Midterm 2_ Uno Starter Code/Configs/Decks/Regular.txt");
  std::string line;
  while (getline(file, line)) {
    file >> std::ws;

    std::stringstream ss;
    ss << line;
    card = nullptr;
    ss >> numCards;
    ss >> color;
    ss >> value;
    card = new Card(value, color);
    deck = new Deck(numCards, card);
    deck->setDeck();

    for (int i = 0; i < deck->getDeck().size(); i++) {
      std::cout << deck->getDeck().at(i)->getColor() << " "
                << deck->getDeck().at(i)->getValue() << std::endl;
    }

  }



//  for (int i = 0; i < numAndTypeStorage.size(); i++) {
//
//    for (int j = 1; j <= numAndTypeStorage.at(i)->getNumCards(); j++) {
//      playingDeck.push_back(numAndTypeStorage.at(i)->getCards());
//    }
//
//  }

//  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
//  std::shuffle(playingDeck.begin(), playingDeck.end(), generator);

  //Prints out all the cards in the file
  for (int i = 0; i < playingDeck.size(); i++) {
    std::cout << playingDeck.at(i)->getColor() << " " << playingDeck.at(i)->getValue() << std::endl;
  }
}


//  void hand (){
//    std::vector <Hand*> playerHand;
//
//  Hand* hand;
//
//  std::vector<Player*> players;
//  Player* player;
//  int numPlayers;
//  std::string playerName;
//  std::cout << "Enter the number of players you want: " << std::endl;
//  std::cin >> numPlayers;
//  for (int i = 0; i < numPlayers; i++) {
//    std::cout << "Player " << i + 1 << " enter your name: ";
//    std::cin >> playerName;
//    player = new Player(playerName, 0);
//    players.push_back(player);
//  }
//
//  for (int k = 0; k < players.size(); k++){
//    playingDeck.erase(playingDeck.begin(), playingDeck.begin()+(k*7));
//    for (int i = 0; i < playingDeck.size()/7; i++) {
//      hand = new Hand(playingDeck.at(i));
//      playerHand.push_back(hand);
//    }
//  }
//
//  for (int i = 0; i < players.size(); i++) {
//    std::cout << players.at(i)->getPlayerName()<< ": ";
//
//    for (int n = 0; n < playerHand.size(); n++) {
//      std::cout << playerHand.at(n)->getCardsInHand()->getColor() << " "
//      << playerHand.at(n)->getCardsInHand()->getValue() << ", ";
//    }
//    std::cout<< "\n";
//  }
//}