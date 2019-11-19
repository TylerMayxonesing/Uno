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

bool isNumber(const std::string& str)
{
  char* ptr;
  strtol(str.c_str(), &ptr, 10);
  return *ptr == '\0';
}
