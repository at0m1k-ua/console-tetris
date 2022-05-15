cmake_minimum_required(VERSION 3.16)
project(console_tetris)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(console_tetris src/Main.cpp src/Gui.cpp src/Shape.cpp src/ShapeLoader.cpp src/ShapeState.cpp src/GameField.cpp)
target_link_libraries(console_tetris ${CURSES_LIBRARIES})