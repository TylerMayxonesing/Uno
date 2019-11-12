#ifndef UNO__DECK_H_
#define UNO__DECK_H_

#include "Card.h"
class Deck{
private:
    int aNumCards;
    std::vector<Card*> aDeck;
public:
    Deck(int numCards, std::vector<Card*> deck);
    ~Deck();
    int getNumCards();
    std::vector<Card*> getDeck();

    void setNumCards(int numCards);
    void setDeck(std::vector<Card*> deck);




};

#endif //UNO__DECK_H_