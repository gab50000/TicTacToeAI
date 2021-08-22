#include "QPlayer.hpp"

#include <spdlog/spdlog.h>

#include <algorithm>
#include <optional>

QPlayer::QPlayer(std::shared_ptr<Board> board, Field field)
    : Player(board, field) {}

std::optional<Position> QPlayer::decide_move() {
  std::vector<Position> possible_moves = _board->get_empty_fields();
  std::vector<float> scores(possible_moves.size());

  if (possible_moves.empty()) {
    return {};
  }

  auto state_to_score = [*this](const Position& pos) -> float {
    Board new_board = *_board;
    new_board.set_field(pos, _field);
    std::optional<Field> winner = new_board.get_winner();
    if (winner.has_value()) {
      if (winner.value() == _field) {
        return 1;
      }
      if (winner.value() == opposite(_field)) {
        return -1;
      }
    }

    if (_value_function.find(new_board) != _value_function.end()) {
      SPDLOG_DEBUG("Found value {}", _value_function.at(new_board));
      return _value_function.at(new_board);
    }
    return 0;
  };

  std::transform(possible_moves.begin(), possible_moves.end(), scores.begin(),
                 state_to_score);

  auto max_pos = std::max_element(scores.begin(), scores.end());
  int max_idx = std::distance(scores.begin(), max_pos);
  return possible_moves[max_idx];
}

void QPlayer::update_value_function(const GameRecord& record, double decay) {
  auto winner = record.winner;
  float last_score;
  if (!winner.has_value()) {
    last_score = 0;
  } else if (winner.value() == _field) {
    last_score = 1;
  } else {
    last_score = -1;
  }
}