#include "Deck.h"

Deck::Deck(int numCards, std::vector<Card*> deck) {
    aNumCards = numCards;
    aDeck = deck;
}

int Deck::getNumCards() {
    return aNumCards;
}

std::vector<Card*> Deck::getDeck() {
    return aDeck;
}
void Deck::setDeck(std::vector<Card*> deck) {
    aDeck = deck;
}
void Deck::setNumCards(int numCards) {
    aNumCards = numCards;
}
