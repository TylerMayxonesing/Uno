//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Hand.h"

Hand::Hand(Card* cardsInHand) {
  aCardsInHand = cardsInHand;
}
void Hand::setPlayerHand() {
  std::vector <Card*> playerHand;
  playerHand.push_back(aCardsInHand);
  aPlayerHand = playerHand;
}

std::vector<Card*> Hand::getPlayerHand(){
  return aPlayerHand;
}
Card* Hand::getCardsInHand() {
  return aCardsInHand;
}