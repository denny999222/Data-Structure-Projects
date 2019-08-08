cmake_minimum_required(VERSION 3.12)
project(Assignment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment2a
        main.cpp
        sequence1.cpp
        sequence1.h)

add_executable(Assignment2
        sequence1.cpp
        sequence1.h
        sequence_test.cpp)

add_executable(Assignment2b
        sequence1.cpp
        sequence1.h
        sequence_exam.cpp)