//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Hand.h"

Hand::Hand(std::vector <Card*> playerHand) {
   aPlayerHand = playerHand;
}

std::vector <Card*> Hand::getPlayerHand() {
  return aPlayerHand;
}

void Hand::setPlayerHand(std::vector<Card*> playerHand) {
  aPlayerHand = playerHand;
}