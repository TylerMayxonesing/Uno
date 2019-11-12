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

