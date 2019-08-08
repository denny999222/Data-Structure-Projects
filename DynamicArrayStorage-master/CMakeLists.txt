cmake_minimum_required(VERSION 3.12)
project(Assignment3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment3
        Assignment3.pdf
        sequence2.cpp
        sequence2.h
        sequence2_test.cpp)


add_executable(Assignment3b
        Assignment3.pdf
        sequence2.cpp
        sequence2.h
        sequence2_exam.cpp)

add_executable(Assignment3c
        Assignment3.pdf
        main.cpp
        sequence2.cpp
        sequence2.h)
