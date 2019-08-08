cmake_minimum_required(VERSION 3.12)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment4
        Assignment4.pdf
        main.cpp
        node1.cpp
        node1.h
        sequence3.cpp
        sequence3.h)

add_executable(Assignment4b
        Assignment4.pdf
        node1.cpp
        node1.h
        sequence3.cpp
        sequence3.h
        sequence3_exam.cpp)

add_executable(Assignment4C
        Assignment4.pdf
        node1.cpp
        node1.h
        sequence3.cpp
        sequence3.h
        sequence3_test.cpp)


