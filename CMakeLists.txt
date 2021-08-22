cmake_minimum_required(VERSION 3.20.5)
set(CMAKE_CXX_STANDARD 17)

project(
    TicTacToe
)

add_library(tictactoe STATIC src/Board.hpp src/Board.cpp src/Player.hpp src/Player.cpp)