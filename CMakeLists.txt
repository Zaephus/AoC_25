cmake_minimum_required(VERSION 3.31)
project(AoC_25)

set(CMAKE_CXX_STANDARD 26)

add_executable(AoC_25
    main.cpp
    Helper/TextHandler.cpp
    Helper/TextHandler.h
    Day_3/Day_3.h
)

target_include_directories(AoC_25 PUBLIC
    Helper
)