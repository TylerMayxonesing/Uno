#ifndef UNO__DISCARDPILE_H_
#define UNO__DISCARDPILE_H_

#include "Card.h"

class DiscardPile{
private:

public:
    std::vector<Card> aDiscardPile;
    DiscardPile(std::vector<Card> playedCard);
//    ~DiscardPile();
    std::vector<Card> getDiscardPile();
    void setDiscardPile(std::vector<Card> DiscardPile);

};

#endif //UNO__DISCARDPILE_H_