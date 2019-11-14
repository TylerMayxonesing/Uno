#ifndef UNO__GAME_H_
#define UNO__GAME_H_

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Hand.h"
#include "prefix.h"
#include "InputValidation.h"


std::vector<Card*> readFile();
void startingSetUp();
#endif //UNO__GAME_H_