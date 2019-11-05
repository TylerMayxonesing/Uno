//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Card.h"

Card::Card(std::string value, std::string color){
  m_value = value;
  m_color = color;
}

std::string Card::getValue(){
  return m_value;
}

std::string Card::getColor(){
  return m_color;
}

void Card::setValue(std::string value){
  m_value = value;
}

void Card::setColor(std::string color){
  m_value = color;
}