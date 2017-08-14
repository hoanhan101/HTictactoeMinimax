#import "Board.h"

void Board::init() {
  for(int i = 0; i <= 9; i++) {
    board[i] = 0;
  }
}


void Board::showBoard() {
  std::cout << "-------------" << '\n';;
  for(int i = 1; i <= 9; i++) {
    switch(board[i]) {
    case 0:
      std::cout << "| " << " " << " ";
      break;
    case 1:
      std::cout << "| " << "X" << " ";
      break;
    case 2:
      std::cout << "| " << "O" << " ";
      break;
    default:
      break;
    }

    if(i==3 || i==6 || i==9) {
      std::cout << "|" << '\n';;
      std::cout << "-------------" << '\n';;
    }
  }
}

void Board::displayOpeningMessage() {
  std::cout << '\n';
  std::cout << "WELCOME TO TIC TAC TOE" << '\n';;
  std::cout << '\n';
}

void Board::displayInstruction() {
  std::cout << "HERE IS THE BOARD WITH POSITION NUMBER" << '\n';
  std::cout << '\n';
  std::cout << "-------------" << '\n';;
  std::cout << "| 1 | 2 | 3 |" << '\n';
  std::cout << "-------------" << '\n';;
  std::cout << "| 4 | 5 | 6 |" << '\n';
  std::cout << "-------------" << '\n';;
  std::cout << "| 7 | 8 | 9 |" << '\n';
  std::cout << "-------------" << '\n';;
  std::cout << '\n';
  std::cout << "PLAYER USE 'X', AI USE 'O'" << '\n';
  std::cout << "CHOOSE WISELY AND GOOD LUCK!" << '\n';
  std::cout << '\n';

}
