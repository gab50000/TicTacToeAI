#pragma once
#include <memory>
#include <optional>
#include <random>

#include "Player.hpp"

class RandomPlayer : public Player {
 private:
  std::mt19937 _gen;

 public:
  RandomPlayer(std::shared_ptr<Board> board, Field field);
  std::optional<Position> decide_move() override;
};