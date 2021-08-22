#include <iostream>
#include <memory>

#include "Board.hpp"
#include "Player.hpp"

int main() {
  auto board = std::make_shared<Board>();

  RandomPlayer player1(board, Field::O);
  RandomPlayer player2(board, Field::X);

  std::cout << player1.decide_move().value() << std::endl;
}