//
// Created by Ray Ngan on 11/2/19.
//
#include <iostream>
#include <string>
#ifndef UNO_RULES_H
#define UNO_RULES_H


class Rules {
public:
    Rules();
    static int startingHandSize(int starting_hand);
    static int unoCallOutPenalty(int uno_penalty);
    static int badUnoCalloutPenalty(int bad_uno_penalty);
    static int drawLimit(int max_draw);

    enum level { must_play , reneging};
    static int mustPlayCardEachTurn();
    int renegingfunc();

};


#endif //UNO_RULES_H
