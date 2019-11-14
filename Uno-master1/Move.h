//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__MOVE_H_
#define UNO__MOVE_H_
#include "Player.h"
class Move{
 private:
  std::string aPlayerMove;
  Card* aCard1;public:
  Move(std::string playerMove);
  ~Move();
  std::string getMove();
  void setMove(std::string playerMove);
};

#endif //UNO__MOVE_H_
