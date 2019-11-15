//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Card.h"

Card::Card(const int& value, const std::string& color){
  aValue = value;
  aColor = color;
}

int Card::getValue()const{
  return aValue;
}

std::string Card::getColor() const{
  return aColor;
}

void Card::setValue(int value){
  aValue = value;
}

void Card::setColor(std::string color){
  aColor = color;
}



bool Card::operator== (const Card* rhs) const{
  if ((this->getValue()== rhs->getValue() &&
        this->getColor()== rhs->getColor())) {
    return true;
  }
}



bool Card::operator!= (const Card* rhs) const
{
  if ((this->getValue()!= rhs->getValue() &&
      this->getColor()!= rhs->getColor())) {
    return false;
  }
}
