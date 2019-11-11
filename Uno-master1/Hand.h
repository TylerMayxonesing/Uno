//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__HAND_H_
#define UNO__HAND_H_

#include "Card.h"

class Hand{
 public:
  Card* aCardsInHand;
  Hand(Card*);
  ~Hand();
  Card* getCardsInHand();
};

#endif //UNO__HAND_H_
