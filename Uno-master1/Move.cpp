//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Move.h"

Move::Move(std::string playerMove){
  aPlayerMove = playerMove;
}

std::string Move::getMove() {
  return aPlayerMove;
}

void Move::setMove(std::string playerMove) {
  aPlayerMove = playerMove;
}

bool Move::canPlay(Card* Card1, Card* Card2) {
  if (Card1->getColor()==Card2->getColor()||
  Card1->getValue()==Card2->getValue()){
    return true;
  }
}