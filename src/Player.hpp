#pragma once

#include <memory>

class Board;
enum class Field;

class Player {
  std::shared_ptr<Board> _board;

 public:
  Player(std::shared_ptr<Board> board);
};