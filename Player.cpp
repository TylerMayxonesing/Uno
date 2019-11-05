//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Player.h"

Player::Player (std::string name, int score){
  m_playerName = name;
  m_score = score;
}

std::string Player::getPlayerName(){
  return m_playerName;
}

int Player::getScore(){
  return m_score;
}

void Player::setPlayerName(std::string name){
  m_playerName = name;
}

void Player::setScore(int score){
  m_score = score;
}

void Player::retrieveCardFfromDrawPile(Card* playerCard) {
  m_drawpile.push_back(playerCard);
}

void Player::addCardFromDrawPile(Card* playerCard) {
  m_playerHand.push_back(playerCard);
}

std::string Player::displayHand() {
  for (int i = 0; i < m_playerHand.size(); i++){
    std::cout << m_playerHand.at(i) -> getValue() << " " << m_playerHand.at(i) -> getColor()
    << std::endl;
  }

}