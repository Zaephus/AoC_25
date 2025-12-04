
#pragma once

#include <string>
#include <vector>

#include "TextHandler.h"

inline void dayOne() {
    int counter = 0;

    int currentPos = 50;

    const std::vector<std::string> lines = TextHandler::loadFile("Day_1/day_1.txt");

    for(const auto & line : lines) {
        const char dir = line[0];

        const int number = std::stoi(line.substr(1));

        for(int n = number; n > 0; n--) {
            switch(dir) {
                case 'L': currentPos--; break;
                case 'R': currentPos++; break;
                default: break;
            }

            if(currentPos > 99) {
                currentPos = 0;
            }
            if(currentPos < 0) {
                currentPos = 99;
            }

            if(currentPos == 0) {
                counter++;
            }
        }
    }

    std::cout << counter << std::endl;
}