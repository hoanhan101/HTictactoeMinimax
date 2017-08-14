#import "Controller.h"

Controller::Controller() {

}

bool Controller::checkState() {
  bool isDraw = true;
  if ((myBoard.board[1] == myBoard.board[2] && myBoard.board[2] == myBoard.board[3] && myBoard.board[1] != 0) ||
      (myBoard.board[4] == myBoard.board[5] && myBoard.board[5] == myBoard.board[6] && myBoard.board[4] != 0) ||
      (myBoard.board[7] == myBoard.board[8] && myBoard.board[8] == myBoard.board[9] && myBoard.board[7] != 0) ||
      (myBoard.board[1] == myBoard.board[5] && myBoard.board[5] == myBoard.board[9] && myBoard.board[1] != 0) ||
      (myBoard.board[3] == myBoard.board[5] && myBoard.board[5] == myBoard.board[7] && myBoard.board[3] != 0) ||
      (myBoard.board[1] == myBoard.board[4] && myBoard.board[4] == myBoard.board[7] && myBoard.board[1] != 0) ||
      (myBoard.board[2] == myBoard.board[5] && myBoard.board[5] == myBoard.board[8] && myBoard.board[2] != 0) ||
      (myBoard.board[3] == myBoard.board[6] && myBoard.board[6] == myBoard.board[9] && myBoard.board[3] != 0)) {
        if(myHuman.isTurn() == true) {
          state = XWIN;
        } else {
          state = OWIN;
        }
      } else {
        for(int i = 1; i <= 9; i++) {
          if(myBoard.board[i] == 0)
            isDraw = false;
          }
          if(isDraw == true)
            state = DRAW;
          }
  return true;
}

bool Controller::createMoveList(int board[], std::list<int>& moveList) {
  for(int i = 1; i <= 9; i++) {
    if(myBoard.board[i] == 0) {
      moveList.push_back(i);
    }
  }
  return true;
}

int	Controller::minimax() {
  std::list<int> moveList;
  int bestMove;
  int value = MIN;
  int minMoveValue;

  createMoveList(myBoard.board, moveList);

  while(!moveList.empty()) {
    myHuman.setTurn(false);
    myAI.setTurn(true);

    myBoard.board[moveList.front()] = 2;

    checkState();

    if(state == OWIN) {
      state = PLAYING;
      bestMove = moveList.front();
      myBoard.board[moveList.front()] = 0;
      return bestMove;
    }

    minMoveValue = minMove(myBoard.board);

    if(minMoveValue >= value) {
      value = minMoveValue;
      bestMove = moveList.front();
    }

    myBoard.board[moveList.front()] = 0;
    moveList.pop_front();
  }

  return bestMove;
}

int	Controller::minMove(int board[]) {
  std::list<int> moveList;
  int value = MAX;
  int maxMoveValue;

  createMoveList(myBoard.board, moveList);

  while(!moveList.empty()) {
    myHuman.setTurn(true);
    myAI.setTurn(false);

    myBoard.board[moveList.front()] = 1;

    checkState();

    if(state == XWIN) {
      state = PLAYING;
      myBoard.board[moveList.front()] = 0;
      return MIN;
    } else if(state == DRAW) {
      state = PLAYING;
      myBoard.board[moveList.front()] = 0;
      return 0;
    } else {
      maxMoveValue = maxMove(myBoard.board);
      if(maxMoveValue <= value) {
        value = maxMoveValue;
      }
    }

    myBoard.board[moveList.front()] = 0;
    moveList.pop_front();
  }

  return value;
}

int	Controller::maxMove(int board[]) {
  std::list<int> moveList;
	int value = MIN;
	int minMoveValue;

	createMoveList(myBoard.board, moveList);

	while(!moveList.empty()) {
		myHuman.setTurn(false);
		myAI.setTurn(true);

		myBoard.board[moveList.front()] = 2;

		checkState();

    if(state == OWIN) {
			state = PLAYING;
			myBoard.board[moveList.front()] = 0;
			return MAX;
		} else if(state == DRAW) {
			state = PLAYING;
			myBoard.board[moveList.front()] = 0;
			return 0;
		} else {
			minMoveValue = minMove(myBoard.board);
			if(minMoveValue >= value) {
				value = minMoveValue;
			}
		}

		myBoard.board[moveList.front()] = 0;
		moveList.pop_front();
	}
	return value;
}

bool Controller::play() {
  int	position;
  bool isValid = false;
  int	bestMove;

  myBoard.init();
  myBoard.displayOpeningMessage();
  myBoard.displayInstruction();
  chooseToGoFirst();

  state = PLAYING;

  while(state != OWIN && state != XWIN && state != DRAW) {
    if(myHuman.isTurn() == true) {
      while(isValid == false) {
        std::cout << '\n' << "Enter the position (1 ~ 9): ";
        std::cin >> position;

        if(myBoard.board[position] == 0 && (position >= 1 && position <= 9)) {
          myBoard.board[position] = 1;
          isValid = true;
        } else {
          std::cout << "Invalid position." << '\n';
        }
      }

      std::cout << "Your move:" << '\n';
      myBoard.showBoard();

      isValid = false;
      checkState();
      myHuman.setTurn(false);
      myAI.setTurn(true);
    }
    else {
      bestMove = minimax();

      myBoard.board[bestMove] = 2;
      std::cout << "AI's move:" << '\n';
      myBoard.showBoard();

      checkState();
      myAI.setTurn(false);
      myHuman.setTurn(true);
    }
  }

  displayResult();

  return playAgain();
}

void Controller::displayResult() {
  std::cout << '\n';

  if(state == XWIN) {
    std::cout << "This is unbelievable!" << '\n';
  } else if(state == OWIN) {
    std::cout << "Sorry! AI Win!" << '\n';
  } else if(state == DRAW) {
    std::cout << "Draw!" << '\n';
  }
}


void Controller::chooseToGoFirst() {
  char inputCharacter;

  std::cout << "Do you want to go first? (Y/N)? " << '\n';
  std::cin >> inputCharacter;
  if(inputCharacter == 'Y' or inputCharacter == 'y') {
    myHuman.setTurn(true);
    myAI.setTurn(false);
  } else {
    myHuman.setTurn(false);
    myAI.setTurn(true);
  }
}

bool Controller::playAgain() {
  char inputCharacter;

  std::cout << '\n';
  std::cout << "Do you want to play again? (Y/N)" << '\n';
  std::cin >> inputCharacter;

  if(inputCharacter == 'Y' or inputCharacter == 'y')
    return true;
  else
    return false;
}
