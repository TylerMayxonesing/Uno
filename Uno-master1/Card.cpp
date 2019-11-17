//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Card.h"

Card::Card(const int value, const std::string color){
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



bool Card::operator== (const Card &rhs) const{
  if (((*this).getValue()== rhs.getValue() &&
      (*this).getColor()== rhs.getColor())) {
    return true;
  }
  else if ((*this).getValue()!= rhs.getValue() ||
      (*this).getColor()!= rhs.getColor()){
    return false;
  }
}

bool Card::operator!= (const Card &rhs) const
{
  return !(*this == rhs);
}

bool Card::matches(const Card& card){
  if(*this==card){
    return true;
  }
  else{
    return false;
  }
}

