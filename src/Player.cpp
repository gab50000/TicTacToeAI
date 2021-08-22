#include "Player.hpp"

#include "Board.hpp"

Player::Player(std::shared_ptr<Board> board, Field field)
    : _board(board), _field(field) {}

RandomPlayer::RandomPlayer(std::shared_ptr<Board> board, Field field)
    : Player(board, field), _gen(std::random_device()()) {}

std::optional<Position> RandomPlayer::decide_move() {
  std::vector<Position> empty_fields = _board->get_empty_fields();
  if (empty_fields.size() == 0) {
    return {};
  }

  if (empty_fields.size() == 1) {
    return empty_fields[0];
  }

  std::uniform_int_distribution<> dist(0, empty_fields.size() - 1);
  int i = dist(_gen);
  return empty_fields[i];
}

void RandomPlayer::make_move(const Position& pos) {}