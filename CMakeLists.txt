cmake_minimum_required(VERSION 3.14)
project(Uno)

set(CMAKE_CXX_STANDARD 14)

add_executable(Uno main.cpp Card.cpp Card.h Deck.cpp Deck.h DiscardPile.cpp DiscardPile.h Game.cpp Game.h Hand.cpp Hand.h InputValidation.cpp InputValidation.h Move.cpp Move.h Player.cpp Player.h Rules.cpp Rules.h StringMethods.cpp StringMethods.h prefix.cpp prefix.h)