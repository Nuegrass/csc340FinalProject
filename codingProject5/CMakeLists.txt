cmake_minimum_required(VERSION 3.27)
project(codingProject5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(codingProject5
        Graph.cpp
        Graph.h
        main.cpp
        unitTest.h)
