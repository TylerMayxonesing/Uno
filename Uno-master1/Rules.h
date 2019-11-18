//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__RULES_H_
#define UNO__RULES_H_

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <istream>

class Rules {
 private:
  int aStartingHand;
  int aUnoPenalty;
  int aBadUnoPenalty;
  int aMaxDraw;
  char aMustPlay;
  char aReneging;

 public:
  Rules();
  void readfile(std::string);
  int startingHandSize();
  int unoCallOutPenalty();
  int badUnoCalloutPenalty();
  int drawLimit();
//
//    enum level { mustPlayenum , renegingenum};
  bool mustPlayCardEachTurn();
  bool renegingFunction();




};


#endif //UNO__RULES_H_