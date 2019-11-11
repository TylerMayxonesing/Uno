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
        must_play = static_cast<level>('T');
//        std::cout<<"it is true";
    }
    else if (input =='f') {
      must_play = static_cast<level>('F');
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
        reneging = static_cast<level>('A');
    }
    if (input == 'l'){
        reneging = static_cast<level>('L');
    }
    return 0;
}

void Rules::readfile(int starting_hand,int uno_penalty,int bad_uno_penalty,int max_draw, char must_play, char reneging) {
    std::ifstream file("/Users/rayngan/desktop/Midterm2/Configs/rules/Default.txt");
    std::string  line;
    std::string items;
    char space;
    char num;
    while (getline(file, line)) {
        file >> std::ws;
        std::stringstream ss;
        ss << line;
        ss >> items;
        ss >> space;
        ss >> num;
        std::istringstream buf(line);

        std::istream_iterator<std::string> beg(buf), end;

        std::vector<std::string> tokens(beg, end); // done!

        for(auto& s: tokens)
            if (s == "StartingHandSize"){starting_hand = num;}

        for(auto& s: tokens)
            if (s == "UnoCalloutPenalty"){uno_penalty = num;}
        for(auto& s: tokens)
            if (s == "BadUnoCalloutPenalty"){bad_uno_penalty = num;}
        for(auto& s: tokens)
            if (s == "DrawLimit"){max_draw = num;}
        for(auto& s: tokens)
            if (s == "MustPlayCardEachTurn"){must_play = num;}
        for(auto& s: tokens)
            if (s == "Reneging"){reneging = num;}


    }


}
