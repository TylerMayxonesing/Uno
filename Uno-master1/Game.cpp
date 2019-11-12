//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Game.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Card.h"
#include <algorithm>
#include "Deck.h"
#include <chrono>
#include "Player.h"
#include "Hand.h"

//Reads through the file and store the cards into a deck
std::vector<Card*> readFile() {
  Deck* deck;
  std::vector<Card*> cards;
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
    deck = nullptr;
    ss >> numCards;
    ss >> color;
    ss >> value;
    for (int i = 1; i <= numCards; i++) {
    card = new Card(value, color);
    cards.push_back(card);
      deck = new Deck(numCards, cards);
    }
  }
//  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
//  std::shuffle(deck->getDeck().begin(), deck->getDeck().end(), generator);

//  for (int i = 0; i < deck->getDeck().size(); i++) {
//    std::cout << deck->getDeck().at(i)->getColor() << " "
//    << deck->getDeck().at(i)->getValue()  << std::endl;
//  }
  return deck->getDeck();

}







//void hand(){
//  auto x = readFile();
//  for (int i = 0; i < x.size(); i++){
//    std::cout << x.at(i)->getColor() << " " << x.at(i)->getValue() << std::endl;
//  }
//  std::vector <Hand*> playerHands;
//  Hand* hand;
//  std::vector <Card*> playerHand;
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
//
//
//
//
//
//
//
//    for (int i = 0; i < 21; i++) {
//      hand = new Hand(playingDeck.at(i));
//      playerHands.push_back(hand);
//    }
//
//  for (int i = 0; i < playerHands.size(); i++){
//    for (int j = 0; j <7 ; j++){
//      playerHand.push_back(playerHands.at(i)->getCardsInHand());
//    }
//    playerHands.erase(playerHands.begin(), playerHands.begin()+6);
//  }
//
//
//
//
//  for (int i = 0; i < players.size(); i++) {
//    std::cout << players.at(i)->getPlayerName()<< ": ";
//    for (int n = 0; n < playerHand.size(); n++) {
//      std::cout << playerHand.at(n)->getColor()<< " " << playerHand.at(n)->getValue()
//                 << ", ";
//    }
//    std::cout<< "\n";
//  }
//}