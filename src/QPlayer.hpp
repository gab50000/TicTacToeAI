#pragma once

#include <optional>
#include <utility>
#include <vector>

#include "Player.hpp"

class QPlayer : public Player {
  using State = Board;
  using Reward = float;

 private:
  std::unordered_map<State, Reward> _value_function;

 public:
  QPlayer(std::shared_ptr<Board> board, Field field);
  std::optional<Position> decide_move() override;
  void update_value_function(const GameRecord& record, double decay);
  std::vector<float> determine_state_scores(const GameRecord& record,
                                            double decay) const;
};