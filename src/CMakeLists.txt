file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${TicTacToe_SOURCE_DIR}/include/tictactoe/*.hpp")

add_library(tictactoe 
    STATIC 
    Board.cpp 
    Player.cpp 
    RandomPlayer.cpp 
    QPlayer.cpp 
    ${HEADER_LIST}
)
target_include_directories(tictactoe PUBLIC ${TicTacToe_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main tictactoe spdlog)
target_link_libraries(tictactoe spdlog)
