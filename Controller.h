#ifndef CONTROLLER_H
#define CONTROLLER_H
#define MAX +100000
#define MIN -100000

#include <iostream>
#include <list>

#import "Board.h"
#import "AI.h"
#import "Human.h"

class Controller {
public:
  Controller();
  enum {PLAYING, OWIN, XWIN, DRAW } state;

  bool checkState();
  void chooseToGoFirst();
  bool createMoveList(int[], std::list<int>&);
  int minimax();
  int minMove(int[]);
  int maxMove(int[]);
  void displayResult();
  bool play();
  bool playAgain();
private:
  Human myHuman;
  AI myAI;
  Board myBoard;
};

#endif
