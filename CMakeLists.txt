cmake_minimum_required(VERSION 3.27)
project(GreedyCache)

set(CMAKE_CXX_STANDARD 17)

add_executable(GreedyCache src/main.cpp
        src/Cache.cpp
        src/Cache.h
        src/Item.cpp
        src/Item.h)
