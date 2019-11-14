//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__DISCARDPILE_H_
#define UNO__DISCARDPILE_H_

#include "Card.h"

class DiscardPile{
 private:
  std::vector<Card*> aDiscardPile;

 public:
  DiscardPile(std::vector<Card*> DiscardPile);
  ~DiscardPile();
  std::vector<Card*> getDiscardPile();
  void makeDiscardPile(std::vector<Card*> DiscardPile);

};

#endif //UNO__DISCARDPILE_H_
