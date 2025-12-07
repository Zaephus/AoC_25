cmake_minimum_required(VERSION 3.31)
project(AoC_25)

set(CMAKE_CXX_STANDARD 26)

add_executable(AoC_25
    main.cpp
    Helper/TextHandler.cpp
    Helper/TextHandler.h
    Day_3/Day_3.h
    Day_4/Day_4.h
    Day_5/Day_5.h
    Day_6/Day_6.h
)

target_include_directories(AoC_25 PUBLIC
    Helper
)