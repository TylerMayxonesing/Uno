//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Player.h"

Player::Player (std::string playerName, int score, std::vector<Card> playerHand): Hand(playerHand){
  aPlayerName = playerName;
  aScore = score;
  aPlayerHand = playerHand;
}

std::string Player::getPlayerName(){
  return aPlayerName;
}

int Player::getScore(){
  return aScore;
}

std::vector<Card> Player::getHands() {
  return aPlayerHand;
}

void Player::setPlayerName(std::string playerName){
  aPlayerName = playerName;
}

void Player::setScore(int score){
  aScore = score;
}

void Player::setPlayerHand(std::vector<Card> playerHand) {
  aPlayerHand = playerHand;
}

