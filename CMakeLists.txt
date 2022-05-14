cmake_minimum_required(VERSION 3.21)
project(console_tetris)

set(CMAKE_CXX_STANDARD 23)

add_executable(console_tetris src/Gui.cpp src/Main.cpp src/Shape.cpp src/ShapeLoader.cpp src/ShapeState.cpp)
