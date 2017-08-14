#include <iostream>
#import "Board.h"
#import "Player.h"
#import "AI.h"
#import "Human.h"
#import "Controller.h"

int main() {
  Controller myController;
  while (myController.play());
  return 0;
}
