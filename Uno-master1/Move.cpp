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

Player Move::moveType(Player player){
//  if(shortFormInput(aPlayerMove,"play")){
//    playCard(player);
//  }
  if(shortFormInput(aPlayerMove,"draw")){
    std::cout << "draw" << std::endl;
  }
  if(shortFormInput(aPlayerMove,"uno")){
    std::cout << "uno" << std::endl;
  }
  if(shortFormInput(aPlayerMove,"quit")){
    exit(0);
  }
  if(shortFormInput(aPlayerMove,"help")){
    std::cout << "- play card_color card_value [uno]\n"
                 "- draw\n"
                 "- uno player_name\n"
                 "- skip\n"
                 "- quit\n"
                 "- help" << std::endl;
  }
  return player;
}



