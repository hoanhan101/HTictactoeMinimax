#import "Player.h"

Player::Player() {

}

void Player::setTurn(bool turn) {
  playerTurn = turn;
}

bool Player::isTurn() {
  return playerTurn;
}
