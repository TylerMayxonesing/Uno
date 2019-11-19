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

int Player::getScore()const{
  return aScore;
}

std::vector<Card>& Player::getHand() {
  return aPlayerHand;
}

void Player::setPlayerName(std::string playerName){
  aPlayerName = playerName;
}

void Player::setScore(int score){
  aScore = score;
}

void Player::setPlayerHand(Card &cardsFromDeck) {
  aPlayerHand.push_back(cardsFromDeck);
}


void Player::discardCardToDiscardPile(Card card){
  std::vector<Card>::iterator found = std::find(aPlayerHand.begin(), aPlayerHand.end(), card);
  if (found != aPlayerHand.end()){
    aPlayerHand.erase(found);
  }
}

bool Player::operator<(const Player& player)const{
  if((*this).getScore() < player.getScore()){
    return true;
  }
  else{
    return false;
  }
}
