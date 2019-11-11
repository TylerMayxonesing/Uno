//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__DECK_H_
#define UNO__DECK_H_

#include "Card.h"
class Deck{
 private:
  Card* aCards;
  int aNumCards;
 public:
  Deck(int numCards, Card* cards);
  ~Deck();
  int getNumCards();
  Card* getCards();
  void setNumCards(int numCards);
  void setCards(Card* cards);




};

#endif //UNO__DECK_H_
