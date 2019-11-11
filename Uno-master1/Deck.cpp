//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Deck.h"

Deck::Deck(int numCards, Card* cards) {
  aNumCards = numCards;
  aCards = cards;
}

void Deck::setDeck(){
  std::vector<Card*> playingDeck;
  for (int i = 1; i <= aNumCards; i++) {
    playingDeck.push_back(aCards);
  }
  aPlayingDeck = playingDeck;
}
std::vector<Card*> Deck::getDeck() {
  return aPlayingDeck;
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