//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__PLAYER_H_
#define UNO__PLAYER_H_

#include "Hand.h"
#include <algorithm>
class Player:Hand{

 private:
  std::string aPlayerName;
  int aScore;
 public:
  Player(std::string playerName, int score, std::vector<Card> playerHand);
  //~Player();

  std::string getPlayerName();
  int getScore()const;
  std::vector<Card>& getHand();


  void setPlayerName(std::string playerName);
  void setScore(int score);
  void setPlayerHand(Card& playerHand);

  std::string getPlayerMove();
  void setPlayerMove(std::string);
  bool operator<(const Player&)const;

  void discardCardToDiscardPile(Card card);

};
#endif //UNO__PLAYER_H_