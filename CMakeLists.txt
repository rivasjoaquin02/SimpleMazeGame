cmake_minimum_required(VERSION 3.16)
project(SimpleMazeGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(SimpleMazeGame main.cpp Classes/Map.cpp Classes/Map.h Classes/MapCells.cpp Classes/MapCells.h Classes/Character.cpp Classes/Character.h Classes/Game.cpp Classes/Game.h)