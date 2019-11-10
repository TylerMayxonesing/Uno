//
// Created by Ray Ngan on 11/2/19.
//

#include "Rules.h"

int Rules::startingHandSize(int starting_hand) {
    while (true) {
        std::cout << "StartingHandSize : ";
        std::cin >> starting_hand;
        if (starting_hand <= 1) {
            std::cout << "Please enter value greater than 1" << std::endl;
            continue;
        } else {
            return starting_hand;}
    }
}

int Rules::unoCallOutPenalty(int uno_penalty) {
    while (true) {
        std::cout << "UnoCalloutPenalty : ";
        std::cin >> uno_penalty;
        if (uno_penalty <= 0) {
            std::cout << "Please enter value greater than 0" << std::endl;
            continue;
    } else {return uno_penalty;}
}
}

int Rules::badUnoCalloutPenalty(int bad_uno_penalty) {
    while (true) {
        std::cout << "BadUnoCalloutPenalty : ";
        std::cin >> bad_uno_penalty;
        if (bad_uno_penalty <= 0) {
            std::cout << "Please enter value greater than 0" << std::endl;
            continue;
        } else {return bad_uno_penalty;}
    }
}

int Rules::drawLimit(int max_draw) {
    while (true) {
        std::cout<<"DrawLimit : ";
        std::cin>>max_draw;
        if (max_draw <= 1) {
            std::cout << "Please enter value greater than 1" << std::endl;
            continue;
        }
        else if(max_draw == 0) {
            return 0;
        }
        else {return max_draw;}
        }
    }


int Rules::mustPlayCardEachTurn() {
    std::cout<<"DrawLimit : ";
    char input;

    enum level must_play;
    std::cin>>input;
    if (input == 't'){
        must_play = static_cast<level>('True');
//        std::cout<<"it is true";
    }
    else if (input =='f') {
      must_play = static_cast<level>('False');
//        std::cout<<"it is false";
    }

    return 0;
}

int Rules::renegingfunc() {
    std::cout<<"Reneging : ";
    char input;
    std::cin>>input;
    //std::cin>>reneging;
    enum level reneging;
    if (input == 'a'){
        reneging = static_cast<level>('Any');
    }
    if (input == 'l'){
        reneging = static_cast<level>('LastDrawn');
    }
    return 0;
}




