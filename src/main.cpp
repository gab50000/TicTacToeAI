#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <memory>

#include "Board.hpp"
#include "QPlayer.hpp"
#include "RandomPlayer.hpp"

GameRecord play_game(Player& player1, Player& player2) {
  GameRecord record;
  auto board = player1.get_board();

  auto game_over = [&board]() -> bool {
    return board->get_winner().has_value() ||
           board->get_empty_fields().size() == 0;
  };

  while (true) {
    player1.make_move();
    record.update_states(board);
    SPDLOG_DEBUG("\n{}", *board);
    if (game_over()) {
      break;
    }
    player2.make_move();
    record.update_states(board);
    SPDLOG_DEBUG("\n{}", *board);
    if (game_over()) {
      break;
    }
  }
  record.winner = board->get_winner();
  return record;
}

int main() {
  spdlog::set_level(spdlog::level::debug);
  auto board = std::make_shared<Board>();

  RandomPlayer player1(board, Field::O);
  QPlayer player2(board, Field::X);

  GameRecord record = play_game(player1, player2);

  if (record.winner.has_value()) {
    std::cout << "Winner is " << record.winner.value() << std::endl;
  }
}

void train(QPlayer& player, int n_epochs) {
  for (int epoch = 0; epoch < n_epochs; epoch++) {
  }
}
