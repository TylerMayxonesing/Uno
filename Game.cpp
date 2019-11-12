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
    std::ifstream file("/Users/rayngan/Desktop/Midterm2/Configs/Decks/Regular.txt");
    std::string line;
    while (getline(file, line)) {
        file >> std::ws;
        std::stringstream ss;
        ss << line;
        card = nullptr;
        //deck = nullptr;
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
    std::minstd_rand generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(deck.begin(), deck.end(), generator);
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
//    std::cout << hand->getPlayerHand().at(0)->getColor() << " "
//        << hand->getPlayerHand().at(0)->getValue() << ", " << std::endl;



        players.at(i)->setPlayerHand(hand);
    }

    for(int i = 0; i < players.size(); i++){
        std::cout << players.at(i)->getPlayerName() << ": ";
        for(int j = 0; j < players.at(i)->getHands()->getPlayerHand().size(); j++) {
            std::cout << players.at(i)->getHands()->getPlayerHand().at(j)->getColor()
                      << " " << players.at(i)->getHands()->getPlayerHand().at(j)->getValue() << ", ";
        }
        std::cout << "\n";
    }
}