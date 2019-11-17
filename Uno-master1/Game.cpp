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
#include <functional>

//Reads through the file and store the cards into a deck
std::vector<Card> readFile() {
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

  std::cout << "All the Cards in the file: ---------------------------------------------------------------------------" << std::endl;
  for (int i = 0; i < deck.getDeck().size(); i++) {
    std::cout << deck.getDeck().at(i).getColor() << " "
    << deck.getDeck().at(i).getValue()  << std::endl;
  }
  return deck.getDeck();

}







void hand() {
  std::vector<Card> deck = readFile();
//  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
//  std::shuffle(deck.begin(), deck.end(), generator);

  std::vector<Card> playerHand;
  std::vector<Card> discardPile;
  std::vector<Player> players;
  Player player(" ", 0, playerHand);
  int numPlayers;
  std::string playerName;

  std::cout << "Enter the number of players you want: ";
  std::cin >> numPlayers;
  for (int i = 0; i < numPlayers; i++) {
    std::cout << "Player " << i + 1 << " enter your name: ";
    std::cin >> playerName;
    player =  Player(playerName, 0, playerHand);
    players.push_back(player);
  }
  std::cin.ignore();
std::cout << "Player Hands: ------------------------------------------------------------------------------------------" << std::endl;
  for (int i = 0; i < players.size(); i++) {
    for (int j = 0; j < 7; j++) {
      playerHand.push_back(deck.at(j));
    }
    deck.erase(deck.begin(), deck.begin() + 7);
    players.at(i).setPlayerHand(playerHand);
    playerHand.erase(playerHand.begin(), playerHand.begin() + 7);
  }

//Prints out all players Hands
  for (int i = 0; i < players.size(); i++) {
    std::cout << players.at(i).getPlayerName() << ": ";
    for (const auto& j : players.at(i).getHands()) {
      std::cout << j.getColor() << " " << j.getValue() << ", ";
    }

    std::cout << "\n";
  }


//std::cout << (players.at(0)->getHands().at(0) == Card(1, "Red"));

  std::string requestedCard;
  Card cardVersion(0, "Blue");

  std::string color;
  int value;
  bool cardExists = false;
  for (int h = 0; h < 3; h ++) {
    for (int i = 0; i < players.size(); i++) {
      cardExists = false;
      while (cardExists == false) {
        std::cout << players.at(i).getPlayerName() << ": What card do you want?: ";
        std::getline(std::cin, requestedCard);
        std::stringstream ss(requestedCard);
        while (ss >> color >> value) {
          cardVersion = Card(value, color);
        }

        auto cmp  = std::bind(&Card::matches, cardVersion, std::placeholders::_1);
        auto cardToRemove = std::find_if(players.at(i).getHands().begin(), players.at(i).getHands().end(), cmp);
        if(cardToRemove != players.at(i).getHands().end()){ //found the card
          players.at(i).getHands().erase(cardToRemove);
          cardExists = true;
        }
        else {
          std::cout << "Your card is invalid." << std::endl;
        }
      }














    }
  }
}