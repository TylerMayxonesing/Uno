//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__PLAYER_H_
#define UNO__PLAYER_H_

#include "Hand.h"

class Player{

 private:
  std::string aPlayerName;
  int aScore;
  Hand aHands;
 public:
  Player(std::string playerName, int score, Hand hands);
  //~Player();

  std::string getPlayerName();
  int getScore();
  Hand getHands();


  void setPlayerName(std::string playerName);
  void setScore(int score);
  void setPlayerHand(Hand hands);

};
#endif //UNO__PLAYER_H_