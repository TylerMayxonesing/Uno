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

class Rules {
 public:
  Rules();
  static void readfile(int starting_hand,int uno_penalty,int bad_uno_penalty,int max_draw, char must_play, char reneging);
  static int startingHandSize(int starting_hand);
  static int unoCallOutPenalty(int uno_penalty);
  static int badUnoCalloutPenalty(int bad_uno_penalty);
  static int drawLimit(int max_draw);
//
//    enum level { mustPlayenum , renegingenum};
  static int mustPlayCardEachTurn(char must_play);
  static int renegingFunction(char reneging);




};


#endif //UNO__RULES_H_
