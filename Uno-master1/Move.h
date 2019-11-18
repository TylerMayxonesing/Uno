//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__MOVE_H_
#define UNO__MOVE_H_

#include <string>
#include "InputValidation.h"

class Move{
 private:
  std::string aPlayerMove;
  std::string aColor;
  std::string aValue;
  std::string aCallout;
 public:

  Move(const std::string&, const std::string&, const std::string&, const std::string&);
  //~Move();
  std::string moveType()const;
};


#endif //UNO__MOVE_H_
