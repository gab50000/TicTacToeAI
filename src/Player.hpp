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
  virtual void make_move() = 0;
  void set_field(const Position& pos);
};

class QPlayer : public Player {
  using State = std::vector<std::optional<Field>>;
  using Action = Position;
  using Reward = double;

 private:
  std::unordered_map<std::pair<State, Action>, Reward> _value_function;
};