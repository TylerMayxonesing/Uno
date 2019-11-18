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
 public:
  Rules();
  static void readfile(int starting_hand =0 , int uno_penalty= 0, int bad_uno_penalty= 0, int max_draw=0, char must_play=0, char reneging=0);
  int startingHandSize(int starting_hand);
  int unoCallOutPenalty(int uno_penalty);
  int badUnoCalloutPenalty(int bad_uno_penalty);
  int drawLimit(int max_draw);
//
//    enum level { mustPlayenum , renegingenum};
  int mustPlayCardEachTurn(char must_play);
  int renegingFunction(char reneging);




};


#endif //UNO__RULES_H_