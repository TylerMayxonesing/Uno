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
  int aValue;
  std::string aColor;
 public:
  Card(int value, std::string color);
  ~Card();
  int getValue();
  std::string getColor();
  void setValue(int value);
  void setColor(std::string color);

};



#endif //UNO__CARD_H_
