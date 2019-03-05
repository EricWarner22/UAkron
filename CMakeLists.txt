cmake_minimum_required(VERSION 3.6)   # CMake version check
project(GameOfWar)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
 

add_executable(Program main.cpp card.cpp card.h)       # Add executable target with source files listed in SOURCE_FILES variable
