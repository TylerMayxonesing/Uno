//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Move.h"
#include "InputValidation.h"
#include "Game.h"

Move::Move(std::string playerMove){
  aPlayerMove = playerMove;
}

std::string Move::getMove() {
  return aPlayerMove;
}

void Move::setMove(std::string playerMove) {
  aPlayerMove = playerMove;
}

std::string Move::moveType(){
  if(shortFormInput(aPlayerMove,"play")){
   return "play";
  }
  if(shortFormInput(aPlayerMove,"draw")){
    return "draw";
  }
  if(shortFormInput(aPlayerMove,"uno")){
    return "uno";
  }
  if(shortFormInput(aPlayerMove,"skip")){
    return "skip";
  }
  if(shortFormInput(aPlayerMove,"quit")){
    exit(0);
  }
  if(shortFormInput(aPlayerMove,"help")){
    return  "help";
  }
}



