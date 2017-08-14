#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player {
public:
  Player();

  void setTurn(bool);
  bool isTurn();
private:
  bool playerTurn;

};

#endif
