//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Move.h"

Move::Move(std::string playerMove){
  aPlayerMove = playerMove;
}

std::string Move::getMove() {
  return aPlayerMove;
}

void Move::setMove(std::string playerMove) {
  aPlayerMove = playerMove;
}

//void Move::moveType(){
//  std::string requestedCard;
//  std::vector<std::string>::iterator playerCard;
//  if(aPlayerMove == "play"){
//    do {
//      std::cout << "What card would you like to play?: ";
//      std::getline(std::cin, requestedCard);
//    }
//    while ();
//  }
//}



