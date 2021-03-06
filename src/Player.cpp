#include <tictactoe/Board.hpp>
#include <tictactoe/Player.hpp>

Player::Player(std::shared_ptr<Board> board, Field field)
    : _board(board), _field(field) {}

void Player::set_field(const Position& pos) {
  _board->set_field(pos, _field);
}

void Player::make_move() {
  auto move = decide_move();
  if (move.has_value()) {
    set_field(move.value());
  }
}
std::shared_ptr<Board> Player::get_board() const {
  return _board;
}

void Player::set_board(std::shared_ptr<Board> board) {
  _board = board;
}