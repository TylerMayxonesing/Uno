//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Card.h"
#include <algorithm>
#include "Deck.h"
//std::vector<Card*> cards;
void readFile() {
  Deck* deck;
  std::vector<Deck*> playingDeck;
  Card*card;
  int numCards;
  int value;
  std::string color;
  std::ifstream file("C:/Users/Tyler Mayxonesing/Desktop/Midterm 2_ Uno Starter Code/Configs/Decks/Regular.txt");
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
    //cards.push_back(card);
    playingDeck.push_back(deck);
  }
  for (int i = 0; i < playingDeck.size(); i++){
    std::cout << playingDeck.at(i) -> getCards()-> getColor() << " "  << playingDeck.at(i)->getCards()->getValue() <<  std::endl;
  }

}