#include <iostream>
#include "Game.h"
#include "InputValidation.h"
int main(int argc, char** argv) {
  Game().readFile(argv[1], argv[2], argv[3]);
  return 0;
}