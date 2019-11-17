

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
#include "DiscardPile.h"
#include <functional>
#include "InputValidation.h"
#include "Move.h"

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

//    std::cout << "All the Cards in the file: ---------------------------------------------------------------------------" << std::endl;
//    for (int i = 0; i < deck.getDeck().size(); i++) {
//        std::cout << deck.getDeck().at(i).getColor() << " "
//                  << deck.getDeck().at(i).getValue()  << std::endl;
//    }
//    std::cout<<"The deck is before anything:"<<deck.getDeck().size();
    return deck.getDeck();
}


void hand() {
    std::vector<Card> deck = readFile();
//  std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
//  std::shuffle(deck.begin(), deck.end(), generator);

    std::vector<Card> playerHand;
    std::vector<Card> discardedCards;
    std::vector<Player> players;
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


    for ( int i = 0; i < 1 ; i++){
        discardedCards.push_back(deck.at(i));
        deck.erase(deck.begin(),deck.begin()+1);
        discard.setDiscardPile(discardedCards);
        discardedCards.erase(discardedCards.begin(),discardedCards.begin()+1);
    }
//  for (int i = 0; i <1; i++) {
//    std::cout << "Discard pile: "<<discard.getDiscardPile().at(i).getColor() << " "
//              << discard.getDiscardPile().at(i).getValue() << std::endl;
//  }


//Prints out all players Hands
    for (int i = 0; i < players.size(); i++) {
        std::cout << players.at(i).getPlayerName() << ": ";
        for (const auto& j : players.at(i).getHand()) {
            std::cout << j.getColor() << " " << j.getValue() << ", ";
        }
        std::cout << "\n";
    }



    std::string playerResponse;
    Move playerMove(playerResponse);

    std::string buf;                 // Have a buffer string
    std::vector<std::string> tokens; // Create vector to hold our words
    std::string move;
    std::string card;


    for (int i = 0; i < players.size(); i++) {
            std::cout << players.at(i).getPlayerName() << " what would you like to do? ";
            std::getline(std::cin, playerResponse);
            std::stringstream ss(playerResponse);
            while (ss >> buf)
            tokens.push_back(buf);
            for (int i = 0; i < tokens.size(); i++) {
            move = tokens.at(0);
            card = tokens.at(1) + tokens.at(2);}
            players.at(i) = Move(move).moveType(players.at(i));

    }

    }



//

            //players.at(i) = playCard(players.at(i));

