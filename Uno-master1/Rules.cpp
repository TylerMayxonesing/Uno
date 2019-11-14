//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Rules.h"

int Rules::startingHandSize(int starting_hand) {
  return starting_hand;}

int Rules::unoCallOutPenalty(int uno_penalty) {
  return uno_penalty;
}


int Rules::badUnoCalloutPenalty(int bad_uno_penalty) {
  return bad_uno_penalty;}


int Rules::drawLimit(int max_draw) {
  if(max_draw == 'N') {
    return 0;
  }
  else {return max_draw;}
}



int Rules::mustPlayCardEachTurn(char must_play) {



  if (must_play == 't'){
    return 1;
//        std::cout<<"it is true";
  }
  else if (must_play =='f') {
    return 0;
//        std::cout<<"it is false";
  }

}

int Rules::renegingFunction(char reneging) {
//    enum level reneging;
  if (reneging == 'A'){
    return 0;
//        reneging = static_cast<level>('A');
  }
  if (reneging == 'L'){
    return 1;
//        reneging = static_cast<level>('L');
  }

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
      if (s == "StartingHandSize"){starting_hand = num-48;}
    for(auto& s: tokens)
      if (s == "UnoCalloutPenalty"){uno_penalty = num-48;}
    for(auto& s: tokens)
      if (s == "BadUnoCalloutPenalty"){bad_uno_penalty = num-48;}
    for(auto& s: tokens)
      if (s == "DrawLimit"){if (num == 78) {max_draw = 0;}else{max_draw = num-48;}}
//            else{max_draw = num;}

    for(auto& s: tokens)
      if (s == "MustPlayCardEachTurn"){must_play = num;}
    for(auto& s: tokens)
      if (s == "Reneging"){reneging = num;}
  }
  Rules::startingHandSize(0);
  Rules::unoCallOutPenalty(0);
  Rules::badUnoCalloutPenalty(0);
  Rules::drawLimit(0);
  Rules::mustPlayCardEachTurn(0);
  Rules::renegingFunction(0);



}