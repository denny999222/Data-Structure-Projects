cmake_minimum_required(VERSION 3.12)
project(Assignment5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment5
        maze.cpp
        maze.h
        recursion.cpp)

add_executable(Assignment5b
        maze.cpp maze.h recursion.cpp
        )
