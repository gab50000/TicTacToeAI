#include "gtest/gtest.h"
#include "tictactoe/Board.hpp"

TEST(Board, GetEmptyFields) {
  Board board;
  auto empty_fields = board.get_empty_fields();
  EXPECT_EQ(empty_fields.size(), 9);
  board.set_field({0, 0}, Field::O);
  empty_fields = board.get_empty_fields();
  EXPECT_EQ(empty_fields.size(), 8);
}
