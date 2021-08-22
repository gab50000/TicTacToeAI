#include <iostream>
#include <memory>

#include "Board.hpp"
#include "Player.hpp"

int main() {
  auto board = std::make_shared<Board>();

  RandomPlayer player1(board, Field::O);
  RandomPlayer player2(board, Field::X);

  while (!board->get_winner().has_value()) {
    std::cout << *board << std::endl << std::endl;
    player1.make_move();
    player2.make_move();
  }
  std::cout << "Game Over:" << std::endl;
  std::cout << *board << std::endl << std::endl;
}