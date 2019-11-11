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

//Reads through the file and store the cards into a deck
void readFile() {
  Deck* deck;
  std::vector<Deck*> playingDeck;
  Card*card;
  int numCards;
  int value;
  std::string color;
  std::ifstream file("/Users/rayngan/desktop/Midterm2/Configs/Decks/Regular.txt");
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
  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::shuffle(playingDeck.begin(), playingDeck.end(), generator);

  //Prints out all the cards in the file
  for (int i = 0; i < playingDeck.size(); i++){
    std::cout << playingDeck.at(i) -> getNumCards() << " " << playingDeck.at(i) -> getCards()-> getColor() << " "  << playingDeck.at(i)->getCards()->getValue() <<  std::endl;
  }
}