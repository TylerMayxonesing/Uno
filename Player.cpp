#include "Player.h"

Player::Player (std::string playerName, int score, Hand* hands){
    aPlayerName = playerName;
    aScore = score;
    aHands = hands;
}

std::string Player::getPlayerName(){
    return aPlayerName;
}

int Player::getScore(){
    return aScore;
}

Hand* Player::getHands() {
    return aHands;
}

void Player::setPlayerName(std::string playerName){
    aPlayerName = playerName;
}

void Player::setScore(int score){
    aScore = score;
}

void Player::setPlayerHand(Hand* hands) {
    aHands = hands;
}