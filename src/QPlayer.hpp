#pragma once

#include <optional>
#include <utility>
#include <vector>

#include "Player.hpp"

class QPlayer : public Player {
  using State = std::vector<std::optional<Field>>;
  using Action = Position;
  using Reward = float;

 private:
  std::unordered_map<Board, Reward> _value_function;

 public:
  QPlayer(std::shared_ptr<Board> board, Field field);
  std::optional<Position> decide_move() override;
  void update_value_function(const GameRecord& record, double decay);
};