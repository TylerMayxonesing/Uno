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

//Player playCard(Player player) {
//  std::string requestedCard;
//  Card cardVersion(0, "Blank");
//  std::string color;
//  int value;
//  bool cardExists = false;
//  while (cardExists == false) {
//    std::cout << player.getPlayerName() << ": What card do you want?: ";
//    std::getline(std::cin, requestedCard);
//    std::stringstream ss(requestedCard);
//    while (ss >> color >> value) {
//      cardVersion = Card(value, color);
//    }
//    auto cardToRemove = std::find(player.getHand().begin(), player.getHand().end(), cardVersion);
//    if(cardToRemove != player.getHand().end()){ //found the card
//      player.getHand().erase(cardToRemove);
//      cardExists = true;
//    } else {
//      std::cout << "Your card is invalid." << std::endl;
//    }
//  }
//  return player;
//}
