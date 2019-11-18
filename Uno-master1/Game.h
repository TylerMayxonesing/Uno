//
// Created by T Alpha 1 on 11/2/2019.
//

#ifndef UNO__GAME_H_
#define UNO__GAME_H_

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Hand.h"
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "DiscardPile.h"
#include <functional>
#include "InputValidation.h"
#include "Move.h"

//std::vector<Card> readFile();

//void game();

//Player& playCard(Player);
class Game{
 private:
  std::vector<Card> aDiscardPile;
  std::vector<Card> aDeck;
  std::vector<Player> aPlayers;
  std::vector <Card> aDrawPile;

 public:
  Game();
  //~Game();
  void readFile();
  void playGame();
  bool playCard(Player& player, Card card);
  void draw(Player& player);
  bool uno(std::string);


};
#endif //UNO__GAME_H_