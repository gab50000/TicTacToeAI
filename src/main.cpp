#include <iostream>
#include <memory>

#include "Board.hpp"
#include "QPlayer.hpp"
#include "RandomPlayer.hpp"
#include "spdlog/spdlog.h"

int main() {
  spdlog::info("Hello");
  auto board = std::make_shared<Board>();

  RandomPlayer player1(board, Field::O);
  QPlayer player2(board, Field::X);

  while (!board->get_winner().has_value() &&
         !board->get_empty_fields().size() == 0) {
    std::cout << *board << std::endl << std::endl;
    player1.make_move();
    player2.make_move();
  }
  std::cout << "Game Over:" << std::endl;
  if (board->get_winner().has_value()) {
    std::cout << board->get_winner().value() << " wins" << std::endl;
  }
  std::cout << *board << std::endl << std::endl;
}

std::vector<Board> play_game(Player& player1, Player& player2) {
  std::vector<Board> states;
  return states;
}

void train(QPlayer& player, int n_epochs) {}