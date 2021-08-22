#include "Board.hpp"

#include <iostream>

Position::Position(int i, int j) {
  if (i < 0 || i > 2) {
    throw OutOfBoundsException();
  }
  if (j < 0 || j > 2) {
    throw OutOfBoundsException();
  }

  this->i = i;
  this->j = j;
}

std::ostream& operator<<(std::ostream& os, const Position& pos) {
  os << "Position{" << pos.i << ", " << pos.j << "}";
  return os;
}

Board::Board()
    : _board({
          {{}, {}, {}},
          {{}, {}, {}},
          {{}, {}, {}},
      }) {}
std::vector<Position> Board::get_empty_fields() {
  std::vector<Position> empty_fields;
  for (int i = 0; i < _board.size(); i++) {
    for (int j = 0; j < _board[i].size(); j++) {
      if (!_board[i][j].has_value()) {
        empty_fields.push_back({i, j});
      }
    }
  }
  return empty_fields;
}