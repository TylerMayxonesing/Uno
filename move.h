//
// Created by Ray Ngan on 11/4/19.
//
#include <iostream>
#include<vector>
#include <string>


#ifndef UNO_MOVE_H
#define UNO_MOVE_H


class move {
public:
    void ask(std::string player_name);
    void draw(std::vector<int> deck, std::vector<int> hand);
    void play(std::vector<int> hand, std::vector <int> discard_pile, std::string answer);
    void skip();
    void quit();
    void uno();


private:
    int top_card;
    std::string answer;

};


#endif //UNO_MOVE_H
