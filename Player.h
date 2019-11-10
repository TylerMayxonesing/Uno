//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__PLAYER_H_
#define UNO__PLAYER_H_

#include "Card.h"

class Player{

 private:
  std::string aPlayerName;
  std::vector<Card* > aDrawPile;
  int aScore;
  void discard(Card* playerCard);

 public:
  Player(std::string name, int score);
  //~Player();
  std::string getPlayerName();
  int getScore();

  void setPlayerName(std::string name);
  void setScore(int score);
  std::string displayHand();
  void addCardFromDrawPile(Card* playerCard);
  void retrieveCardFfromDrawPile(Card* playerCard);
  void play();
  std::vector <Card*> aPlayerHand;
};
#endif //UNO__PLAYER_H_
