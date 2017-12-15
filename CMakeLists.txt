cmake_minimum_required(VERSION 3.8)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp AdjMGraph.cpp AdjMGraph.h AdjMGraphCreate.h Dijkstra.h)
add_executable(Dijkstra ${SOURCE_FILES} AdjMGraph.cpp AdjMGraph.h AdjMGraphCreate.h Dijkstra.h)