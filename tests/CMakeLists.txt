file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${TicTacToe_SOURCE_DIR}/include/tictactoe/*.hpp")

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG master
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(tests tests/test_Board.cpp)
target_link_libraries(tests gtest_main tictactoe)
get_target_property(tictactoe_INCLUDES tictactoe INCLUDE_DIRECTORIES)
target_include_directories(tests PRIVATE ${tictactoe_INCLUDES})