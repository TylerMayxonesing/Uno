//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__HAND_H_
#define UNO__HAND_H_

#include "Card.h"

class Hand{
  std::vector <Card*> aPlayerHand;
 public:
  Card* aCardsInHand;
  Hand(Card*);
  ~Hand();
  Card* getCardsInHand();

  void setPlayerHand();
  std::vector<Card*> getPlayerHand();
};

#endif //UNO__HAND_H_
