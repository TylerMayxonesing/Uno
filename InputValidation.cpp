//
// Created by T Alpha 1 on 11/2/2019.
//

#include "InputValidation.h"

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

std::map<int, std::vector<int>> readingFile(std::string deckFile, std::string rulesFile, std::string seedFile) {
  std::ifstream deck (deckFile);
  std::ifstream rules (rulesFile);
  std::ifstream seed (seedFile);

  std::vector <int> cardType;
  std::map<int, std::vector<int>> configurations;

  //while (deck >> )


}