//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Hand.h"

Hand::Hand(Card* cardsInHand) {
  aCardsInHand = cardsInHand;

}

Card* Hand::getCardsInHand() {
  return aCardsInHand;
}