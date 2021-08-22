#pragma once
#include <memory>
#include <optional>
#include <unordered_map>
#include <utility>

#include "Board.hpp"

// class Board;
// enum class Field;
// class Position;

class Player {
 protected:
  std::shared_ptr<Board> _board;
  Field _field;

 public:
  Player(std::shared_ptr<Board> board, Field field);
  virtual std::optional<Position> decide_move() = 0;
  virtual void make_move();
  void set_field(const Position& pos);
};
