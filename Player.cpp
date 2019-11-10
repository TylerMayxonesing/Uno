//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Player.h"

Player::Player (std::string name, int score){
  aPlayerName = name;
  aScore = score;
}

std::string Player::getPlayerName(){
  return aPlayerName;
}

int Player::getScore(){
  return aScore;
}

void Player::setPlayerName(std::string name){
  aPlayerName = name;
}

void Player::setScore(int score){
  aScore = score;
}

void Player::retrieveCardFfromDrawPile(Card* playerCard) {
  aDrawPile.push_back(playerCard);
}

void Player::addCardFromDrawPile(Card* playerCard) {
  aPlayerHand.push_back(playerCard);
}

std::string Player::displayHand() {
  for (int i = 0; i < aPlayerHand.size(); i++){
    std::cout << aPlayerHand.at(i) -> getValue() << " " << aPlayerHand.at(i) -> getColor()
    << std::endl;
  }

}