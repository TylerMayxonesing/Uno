//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__CARD_H_
#define UNO__CARD_H_

#include <string>
#include <vector>
#include <iostream>

class Card {
 private:
  std::string m_value;
  std::string m_color;
 public:
  Card(std::string value, std::string color);
  ~Card();
  std::string getValue();
  std::string getColor();
  void setValue(std::string username);
  void setColor(std::string password);
};



#endif //UNO__CARD_H_
