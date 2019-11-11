//
// Created by Ray Ngan on 11/2/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef UNO_RULES_H
#define UNO_RULES_H


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


#endif //UNO_RULES_H
