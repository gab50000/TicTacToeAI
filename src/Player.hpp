#pragma once

#include <memory>
#include <optional>
#include <random>

class Board;
enum class Field;
class Position;

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

class RandomPlayer : public Player {
 private:
  std::mt19937 _gen;

 public:
  RandomPlayer(std::shared_ptr<Board> board, Field field);
  std::optional<Position> decide_move() override;
  void make_move() override;
};