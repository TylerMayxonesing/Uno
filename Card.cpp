//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Card.h"

Card::Card(int value, std::string color){
  aValue = value;
  aColor = color;
}

int Card::getValue(){
  return aValue;
}

std::string Card::getColor(){
  return aColor;
}

void Card::setValue(int value){
  aValue = value;
}

void Card::setColor(std::string color){
  aColor = color;
}

//bool Card::canPlay(Card card1, Card card2) {
//  if (card1.aValue == card2.aValue || card1.aColor == card2.aColor){
//    return true;
//  }
//  else{
//    return false;
//  }
//}