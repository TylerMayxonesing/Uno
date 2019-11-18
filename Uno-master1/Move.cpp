//
// Created by T Alpha 1 on 11/2/2019.
//

#include "Move.h"


Move::Move(const std::string& playerMove, const std::string& color, const std::string& value, const std::string& callout ){
  aPlayerMove = playerMove;
  aColor = color;
  aValue = value;
  aCallout = callout;
}




std::string Move::moveType()const{

  if(shortFormInput(aPlayerMove,"skip")){
    return "skip";
  }
  else if(shortFormInput(aPlayerMove,"play") && aCallout == " "){
   return "play";
  }

  else if(shortFormInput(aPlayerMove,"draw")){
    return "draw";
  }
  else if(shortFormInput(aPlayerMove,"play") && shortFormInput(aCallout,"uno")){
    return "selfCallout";
  }
  else if(shortFormInput(aPlayerMove,"uno")){
    return "uno";
  }

  else if(shortFormInput(aPlayerMove,"quit")){
    exit(0);
  }
  else if(shortFormInput(aPlayerMove,"help")){
    return  "help";
  }
}



