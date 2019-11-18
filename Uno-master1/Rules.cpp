//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Rules.h"
#include <iterator>

int Rules::startingHandSize() {
  return aStartingHand;
}

int Rules::unoCallOutPenalty() {
  return aUnoPenalty;
}


int Rules::badUnoCalloutPenalty() {
  return aBadUnoPenalty;}


int Rules::drawLimit() {
  if(aMaxDraw == 'N') {
    return 0;
  }
  else {
    return aMaxDraw;
  }
}




bool Rules::mustPlayCardEachTurn() {



  if (aMustPlay == 't'){
    return true;
//        std::cout<<"it is true";
  }
  else if (aMustPlay == 'f') {
    return false;
//        std::cout<<"it is false";
  }

}

bool Rules::renegingFunction() {
//    enum level reneging;
  if (aReneging == 'A'){
    return false;
//        reneging = static_cast<level>('A');
  }
  if (aReneging == 'L'){
    return true;
//        reneging = static_cast<level>('L');
  }

}
Rules::Rules(){

}
void Rules::readfile(std::string filesName) {
  int starting_hand;
  int uno_penalty;
  int bad_uno_penalty;
  int max_draw;
  char must_play;
  char reneging;
  std::ifstream file(filesName);
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
  aStartingHand = starting_hand;
  aUnoPenalty = uno_penalty;
  aBadUnoPenalty = bad_uno_penalty;
  aMaxDraw = max_draw;
  aMustPlay = must_play;
  aReneging = reneging;

//  std::cout << starting_hand<<std::endl;
//  std::cout << uno_penalty<<std::endl;
//  std::cout << bad_uno_penalty<<std::endl;
//  std::cout << max_draw<<std::endl;
//  std::cout << must_play<<std::endl;
//  std::cout << reneging<<std::endl;


}