#include "Board.hpp"

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

Board::Board()
    : _board({
          {{}, {}, {}},
          {{}, {}, {}},
          {{}, {}, {}},
      }) {}