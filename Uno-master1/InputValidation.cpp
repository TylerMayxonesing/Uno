//
// Created by T Alpha 1 on 11/2/2019.
//

#include "InputValidation.h"

bool shortFormInput(std::string shortInput, std::string longInput){
  shortInput = lower(shortInput);
  longInput = lower(longInput);
  if(shortInput.size() <= longInput.size() &&
      std::equal( shortInput.begin(), shortInput.end(), longInput.begin() )){
    return true;
  }
  else{
    return false;
  }
}

bool isInt(std::string number){
  if(stoi(number)*0 == 0){
  return true;
}
  else{
  return false;
  }
}

