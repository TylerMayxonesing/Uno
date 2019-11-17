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
#include "DiscardPile.h"

//Reads through the file and store the cards into a deck
std::vector<Card> readFile() {
    Card card(0,"blank");
    std::vector<Card> cards;
    Deck deck(0,cards);

    int numCards;
    int value;
    std::string color;
    std::ifstream file("/Users/rayngan/Desktop/Midterm2/Configs/Decks/Regular.txt");
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
//    std::cout<<"The deck is before anything:"<<deck.getDeck().size();
    return deck.getDeck();
}


void hand() {
    std::vector<Card> deck = readFile();
//  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
//  std::shuffle(deck.begin(), deck.end(), generator);

    std::vector<Card> playerHands;
    std::vector<Card> discardedCards;
    //Hand hand(playerHands);
    std::vector<Player*> players;
    Player* player;
    int numPlayers;
    std::string playerName;
    auto discard = DiscardPile(discardedCards);
    std::cout << "Enter the number of players you want: ";
    std::cin >> numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        std::cout << "Player " << i + 1 << " enter your name: ";
        std::cin >> playerName;
        player = new Player(playerName, 0, playerHands);
        players.push_back(player);
    }
    std::cin.ignore();
    std::cout << "Player Hands: ------------------------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < players.size(); i++) {
        for (int j = 0; j < 7; j++) {
            playerHands.push_back(deck.at(j));
        }
        deck.erase(deck.begin(), deck.begin() + 7);
        //hand = Hand(playerHands);
        players.at(i)->setPlayerHand(playerHands);
        playerHands.erase(playerHands.begin(), playerHands.begin() + 7);
    }
//    std::cout<<"The deck is after player drew"<<deck.size();
    for ( int i = 0; i<1 ; i++){
        discardedCards.push_back(deck.at(i));
        deck.erase(deck.begin(),deck.begin()+1);
        discard.setDiscardPile(discardedCards);
        discardedCards.erase(discardedCards.begin(),discardedCards.begin()+1);
    }
//    std::cout<<"The deck is after top card is placed"<<deck.size();
    for (int i = 0; i <1; i++) {
        std::cout << discard.getDiscardPile().at(i).getColor() << " "
                  << discard.getDiscardPile().at(i).getValue() << std::endl;
    }
//    for (int i = 0; i <1; i++) {
//        std::cout << discardedCards.at(i).getColor() << " "
//                  << discardedCards.at(i).getValue() << std::endl;
//    }

//Prints out all players Hands
//    for (int i = 0; i < players.size(); i++) {
//        std::cout << players.at(i)->getPlayerName() << ": ";
//        for (const auto& j : players.at(i)->getHands()) {
//            std::cout << j.getColor() << " " << j.getValue() << ", ";
//        }
//        std::cout << "\n";
//    }


//  Card x = players.at(0).getHands().getPlayerHand().at(0);
//  std::cout << x.getColor() << " " << x.getValue() << std::endl;
//  std::cout << Card(1, "Red").getColor() << " " << Card(1, "Red").getValue() << std::endl;
//  std::cout << (x !=  Card(1,"Red"));

//
//  std::string requestedCard;
//  Card cardVersion(0, "Blue");
//
//  std::string color;
//  int value;
//  bool cardExists = false;
//  for (int h = 0; h < 3; h ++) {
//    for (int i = 0; i < players.size(); i++) {
//      cardExists = false;
//      while (cardExists == false) {
//        std::cout << players.at(i)->getPlayerName() << ": What card do you want?: ";
//        std::getline(std::cin, requestedCard);
//        std::stringstream ss(requestedCard);
//        while (ss >> color >> value) {
//          cardVersion = Card(value, color);
//        }
//
//        const auto& it = std::find(players.at(i)->getHands().getPlayerHand().begin(), players.at(i)->getHands().getPlayerHand().end(), cardVersion);
//        if(it!=players.at(i)->getHands().getPlayerHand().end()){
//          std::cout << "IT " << (*it).getColor() << " " << (*it).getValue()<<std::endl;
//        //players.at(i)->getHands().getPlayerHand().erase(it);
//         for (const auto& j : players.at(i)->getHands().getPlayerHand()) {
//           std::cout << j.getColor() << " " << j.getValue() << ", ";
//         }
//        }











//std::vector<Card> emptyVec;
//std::vector<Card>::iterator it = emptyVec.end();
//        for ( it = players.at(i)->getHands().getPlayerHand().begin();
//             it != players.at(i)->getHands().getPlayerHand().end(); it++) {
//          std::cout << (*it).getColor() << " " << (*it).getValue() << ", " << std::endl;
//          if (*it == cardVersion) {
//            std::cout << "Your card is: " << (*it).getColor() << " " << (*it).getValue() << std::endl;
//
//            std::cout << "After erasing: " << std::endl;
//            for (auto t = players.at(i)->getHands().getPlayerHand().begin();
//                 t != players.at(i)->getHands().getPlayerHand().end(); t++){
//              std::cout << (*t).getColor() << " " << (*t).getValue() << std::endl;
//            }
//            cardExists = true;
//            break;
//          }
//          players.at(i)->getHands().getPlayerHand().erase(players.at(i)->getHands().getPlayerHand().begin(),
//                                                          players.at(i)->getHands().getPlayerHand().begin()+1);
//        }


//      }
//
//
//    }
//  }
}