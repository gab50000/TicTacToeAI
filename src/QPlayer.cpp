#include "QPlayer.hpp"

#include <spdlog/spdlog.h>

#include <algorithm>
#include <optional>
#include <vector>

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

std::vector<float> QPlayer::determine_state_scores(const GameRecord& record,
                                                   double decay) const {
  std::vector<float> scores(record.states.size());

  unsigned int states_length = record.states.size();
  auto winner = record.winner;
  float score;
  if (!winner.has_value()) {
    scores[states_length - 1] = 0;
  } else if (winner.value() == _field) {
    scores[states_length - 1] = 1;
  } else {
    scores[states_length - 1] = -1;
  }

  for (unsigned int i = states_length - 2; i <= 0; i--) {
    scores[i] = decay * scores[i + 1];
  }

  return scores;
}

void QPlayer::update_value_function(const GameRecord& record, double decay) {}