cmake_minimum_required(VERSION 3.20.5)
set(CMAKE_CXX_STANDARD 17)

project(
    TicTacToe
)

include(FetchContent)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG v1.x
)
FetchContent_MakeAvailable(spdlog)

add_library(tictactoe STATIC src/Board.hpp src/Board.cpp src/Player.hpp src/Player.cpp src/RandomPlayer.hpp src/RandomPlayer.cpp src/QPlayer.hpp src/QPlayer.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main tictactoe spdlog)
target_link_libraries(tictactoe spdlog)