//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__PLAYER_H_
#define UNO__PLAYER_H_

#include "Hand.h"

class Player:Hand{

 private:
  std::string aPlayerName;
  int aScore;
 public:
  Player(std::string playerName, int score, std::vector<Card> playerHand);
  Player(const std::vector<Card>& player_hand, const std::string& a_player_name);
  //~Player();

  std::string getPlayerName();
  int getScore();
  std::vector<Card> getHands();


  void setPlayerName(std::string playerName);
  void setScore(int score);
  void setPlayerHand(std::vector<Card> playerHand);

};
#endif //UNO__PLAYER_H_