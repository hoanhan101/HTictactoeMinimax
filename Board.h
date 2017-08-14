#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
public:
  int board[10];
  void init();
  void showBoard();
  void displayOpeningMessage();
  void displayInstruction();
};

#endif
