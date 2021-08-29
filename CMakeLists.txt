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


add_subdirectory(src)