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

int Position::get_i() const {
  return i;
}

int Position::get_j() const {
  return j;
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

std::optional<Field> Board::get_winner() {
  for (int i = 0; i < 3; i++) {
    if (_board[i][0].has_value() && _board[i][0] == _board[i][1] &&
        _board[i][1] == _board[i][2]) {
      return _board[i][0];
    }

    if (_board[0][i].has_value() && _board[0][i] == _board[1][i] &&
        _board[1][i] == _board[2][i]) {
      return _board[0][i];
    }
  }

  if (_board[0][0].has_value() && _board[0][0] == _board[1][1] &&
      _board[1][1] == _board[2][2]) {
    return _board[0][0];
  }

  if (_board[2][0].has_value() && _board[2][0] == _board[1][1] &&
      _board[1][1] == _board[0][2]) {
    return _board[2][0];
  }

  return {};
}

void Board::set_field(const Position& pos, Field field) {
  _board[pos.get_i()][pos.get_j()] = field;
}

std::ostream& operator<<(std::ostream& os, std::optional<Field> field) {
  if (field.has_value() && field.value() == Field::O) {
    os << "O";
  } else if (field.has_value()) {
    os << "X";
  } else {
    os << "-";
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
  os << board._board[0][0] << " | " << board._board[0][1] << " | "
     << board._board[0][2] << std::endl;
  os << board._board[1][0] << " | " << board._board[1][1] << " | "
     << board._board[1][2] << std::endl;
  os << board._board[2][0] << " | " << board._board[2][1] << " | "
     << board._board[2][2];
  return os;
}