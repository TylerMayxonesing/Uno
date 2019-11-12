//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__HAND_H_
#define UNO__HAND_H_

#include "Card.h"

class Hand{
 private:
  std::vector<Card*> aPlayerHand;
 public:
  Hand(std::vector<Card*> playerHand);
  ~Hand();

  std::vector<Card*> getPlayerHand();
  void setPlayerHand(std::vector<Card*> playerHand);
};

#endif //UNO__HAND_H_
