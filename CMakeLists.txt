cmake_minimum_required(VERSION 3.27)
project(CSC340FinalGroupProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(CSC340FinalGroupProject codingProject5/main.cpp
        codingProject5/Graph.h
        codingProject5/Graph.cpp
        codingProject5/unitTest.h
        codingProject6/Organism.h
        codingProject6/Organism.cpp
        codingProject6/Zoomie.h
        codingProject6/Zoomie.cpp
        codingProject6/Swoopie.cpp
        codingProject6/Swoopie.h
        codingProject6/main.cpp
        codingProject6/World.cpp
        codingProject6/World.h
)
