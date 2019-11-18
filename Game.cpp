

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
        aDiscardPile.push_back(aDeck.at(i));
        aDeck.erase(aDeck.begin(),aDeck.begin()+1);
        discard.setDiscardPile(discardedCards);
        discardedCards.erase(discardedCards.begin(),discardedCards.begin()+1);
    }



//Prints out all players Hands
//  for (int i = 0; i < aPlayers.size(); i++) {
//    std::cout << aPlayers.at(i).getPlayerName() << ": ";
//    for (const auto& j : aPlayers.at(i).getHand()) {
//      std::cout << j.getColor() << " " << j.getValue() << ", ";
//    }
//    std::cout << "\n";
//  }



    std::string playerResponse;
    Move playerMove(playerResponse);
    std::string move;
    std::string color;
    int value;
    Card card(0,"blank");
    bool cardExists;

    for (int k = 0; k < 3; ++k) {


    for (int i = 0; i < aPlayers.size(); i++) {
        cardExists = false;
        while (cardExists == false) {

            for (int x = 0; x < aPlayers.size(); x++){
                if(x!= i) {
                    std::cout << aPlayers.at(x).getPlayerName() << ":";
                        for (int u = 0; u < aPlayers.at(x).getHand().size(); u++) {

                            std::cout << aPlayers.at(x).getHand().at(u).getColor() << " "
                                      << aPlayers.at(x).getHand().at(u).getValue() << ", ";
                            if (u == aPlayers.at(x).getHand().size() - 1) {
                                std::cout << "\n";
                            }
                        }
                }
            }

            std::cout << "Top of discard pile: " << aDiscardPile.at(aDiscardPile.size() - 1).getColor() << " "
                      << aDiscardPile.at(aDiscardPile.size() - 1).getValue() << std::endl;
            std::cout << "You hand: ";
            for (int j = 0; j < aPlayers.at(i).getHand().size(); j++) {
                std::cout << aPlayers.at(i).getHand().at(j).getColor() << " "
                          << aPlayers.at(i).getHand().at(j).getValue() << ", ";
                if (j == aPlayers.at(i).getHand().size() - 1) {
                    std::cout << "\n";
                }
            }
            std::cout << aPlayers.at(i).getPlayerName() << ", enter your move or h for help: ";
            std::getline(std::cin, playerResponse);
            std::stringstream ss(playerResponse);
            while (ss >> move >> color >> value) {
                card = Card(value, color);
            }

            playerMove = Move(move);
            if (playerMove.moveType() == "play") {
                cardExists = playCard(aPlayers.at(i), card);
            }
        }
    }
//        if(playerMove.moveType() == "draw"){
//          draw(aPlayers.at(i));
//        }
//        for (int j = 0 ; j < aPlayers.at(i).getHand().size(); j++) {
//          std::cout << aPlayers.at(j).getHand().at(j).getColor() << " " << aPlayers.at(j).getHand().at(j).getValue() << std::endl;
//        }
    }

}

bool Game::playCard(Player& player, Card card) {
    std::string requestedCard;

    bool cardExists = false;
    auto cardToRemove = std::find(player.getHand().begin(), player.getHand().end(), card);
    if(cardToRemove != player.getHand().end()){
        std::cout << (*cardToRemove).getColor() << " " << (*cardToRemove).getValue() << std::endl;
        player.getHand().erase(cardToRemove);
        return  true;
    }
    else {
        std::cout << "Your card is invalid." << std::endl;
        return false;
    }

}

void Game::draw(Player& player) {
    aDrawPile = aDeck;
    player.getHand().push_back(aDrawPile.at(0));
}

void Game::displayPlayerHand(){

}

