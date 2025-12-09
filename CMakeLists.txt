cmake_minimum_required(VERSION 3.31)
project(AoC_25)

set(CMAKE_CXX_STANDARD 26)

add_executable(AoC_25
    main.cpp
    Helper/TextHandler.cpp
    Helper/TextHandler.h
    Day_1/Day_1.h
    Day_2/Day_2.h
    Day_3/Day_3.h
    Day_4/Day_4.h
    Day_5/Day_5.h
    Day_6/Day_6.h
    Day_7/Day_7.h
    Day_8/Day_8.h
)

target_include_directories(AoC_25 PUBLIC
    Helper
)