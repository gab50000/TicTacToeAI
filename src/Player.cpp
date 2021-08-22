#include "Player.hpp"

#include "Board.hpp"

Player::Player(std::shared_ptr<Board> board, Field field)
    : _board(board), _field(field) {}

void Player::set_field(const Position& pos) {
  _board->set_field(pos, _field);
}
