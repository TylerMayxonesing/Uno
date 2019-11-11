//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Deck.h"

Deck::Deck(int numCards, Card* cards) {
  aNumCards = numCards;
  aCards = cards;
}

int Deck::getNumCards() {
  return aNumCards;
}

Card* Deck::getCards(){
  return aCards;
}

void Deck::setNumCards(int numCards) {
  aNumCards = numCards;
}

void Deck::setCards(Card* cards) {
  aCards = cards;
}