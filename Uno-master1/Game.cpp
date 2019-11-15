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
  Card* card;
  std::vector<Card*> cards;

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
    for (int i = 1; i <= numCards; i++) {
      card = new Card(value, color);
      cards.push_back(card);
      deck = new Deck(numCards, cards);
    }
  }

//  for (int i = 0; i < deck->getDeck().size(); i++) {
//    std::cout << deck->getDeck().at(i)->getColor() << " "
//    << deck->getDeck().at(i)->getValue()  << std::endl;
//  }
  return deck->getDeck();

}







void hand(){
  std::vector<Card*> deck = readFile();
//  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
//  std::shuffle(deck.begin(), deck.end(), generator);
  Hand* hand;
  hand = nullptr;
  std::vector<Card*> playerHands;
  std::vector<Player*> players;
  Player* player;
  int numPlayers;
  std::string playerName;

  std::cout << "Enter the number of players you want: ";
  std::cin >> numPlayers;
  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Player " << i + 1 << " enter your name: ";
    std::cin >> playerName;
    player = new Player(playerName, 0, hand);
    players.push_back(player);
  }

  for (int i = 0; i < players.size(); i++) {
    for (int j = 0; j < 7; j++) {
      playerHands.push_back(deck.at(j));
    }
    deck.erase(deck.begin(), deck.begin()+7);
    hand = new Hand(playerHands);
    playerHands.erase(playerHands.begin(), playerHands.begin()+7);
    players.at(i)->setPlayerHand(hand);
  }
//Prints out all players Hands
  for(int i = 0; i < players.size(); i++){
    std::cout << players.at(i)->getPlayerName() << ": ";
    for(const auto& j : players.at(i)->getHands()->getPlayerHand()) {
      std::cout << j->getColor() << " " << j->getValue() << ", ";
    }
    std::cout << "\n";
  }
std::string playerMove;

  std::string requestedCard;
  std::vector<Card*>::iterator playerCard;
  Card* cardVersion;

  std::string color;
  int value;

  Card* x = players.at(0)->getHands()->getPlayerHand().at(0);
  std::cout << (x == new Card(0,"Red"))
  ;
//  for (int i = 0; i < players.size(); i++){
//    bool cardExists = true;
//    do {
//      std::cout << players.at(i)->getPlayerName()<< ": What card do you want?: ";
//      std::getline(std::cin, requestedCard);
//      std::istringstream iss(requestedCard);
//      iss >> color;
//      iss >> value;
//      cardVersion = new Card(value, color);
//      playerCard = find(players.at(i)->getHands()->getPlayerHand().begin(), players.at(i)->getHands()->getPlayerHand().end(), cardVersion);
//      if (playerCard != players.at(i)->getHands()->getPlayerHand().end()) {
//        std::cout << "Your card is: " << *playerCard << '\n';
//        players.at(i)->getHands()->getPlayerHand().erase(playerCard);
//        cardExists = true;
//      }
//      else {
//        std::cout << "You card doesn't exist: \n";
//        cardExists = false;
//      }
//    } while(!cardExists);
//  }
}