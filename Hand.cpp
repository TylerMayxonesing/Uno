#include "Hand.h"

Hand::Hand(std::vector <Card*> playerHand) {
    aPlayerHand = playerHand;
}

std::vector <Card*> Hand::getPlayerHand() {
    return aPlayerHand;
}

void Hand::setPlayerHand(std::vector<Card*> playerHand) {
    aPlayerHand = playerHand;
}