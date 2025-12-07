
#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "TextHandler.h"

inline void daySeven_PartOne() {
    const std::vector<std::string> lines = TextHandler::loadFile("Day_7/day_7.txt");

    int splitAmount = 0;

    std::vector<int> positions { static_cast<int>(lines[0].length()) / 2 };
    std::vector<int> newPositions;

    for(const std::string& line : lines) {
        for(int pos : positions) {
            if(line[pos] != '^') {
                if(std::count(newPositions.begin(), newPositions.end(), pos) == 0) {
                    newPositions.push_back(pos);
                }
                continue;
            }

            int leftPos = pos-1;
            if(leftPos < 0) { leftPos = 0; }

            int rightPos = pos+1;
            if(rightPos >= line.length()) { rightPos = line.length()-1; }

            if(std::count(newPositions.begin(), newPositions.end(), leftPos) == 0) {
                newPositions.push_back(leftPos);
            }
            if(std::count(newPositions.begin(), newPositions.end(), rightPos) == 0) {
                newPositions.push_back(rightPos);
            }
            splitAmount++;
        }

        positions = newPositions;
        newPositions.clear();
    }

    std::cout << splitAmount << std::endl;
}

inline void daySeven_PartTwo() {
    const std::vector<std::string> lines = TextHandler::loadFile("Day_7/day_7.txt");

    std::vector<int> positions { static_cast<int>(lines[0].length()) / 2 };
    std::vector<int> newPositions;

    std::vector<unsigned long long> visited(lines[0].length());
    visited[positions[0]] = 1;

    for(const std::string& line : lines) {
        for(int pos : positions) {
            if(line[pos] != '^') {
                if(std::count(newPositions.begin(), newPositions.end(), pos) == 0) {
                    newPositions.push_back(pos);
                }
                continue;
            }

            int leftPos = pos-1;
            if(leftPos < 0) { leftPos = 0; }

            int rightPos = pos+1;
            if(rightPos >= line.length()) { rightPos = line.length()-1; }

            if(std::count(newPositions.begin(), newPositions.end(), leftPos) == 0) {
                newPositions.push_back(leftPos);
            }
            if(std::count(newPositions.begin(), newPositions.end(), rightPos) == 0) {
                newPositions.push_back(rightPos);
            }

            visited[leftPos] += visited[pos];
            visited[rightPos] += visited[pos];

            visited[pos] = 0;
        }

        positions = newPositions;
        newPositions.clear();
    }

    unsigned long long timelineAmount = 0;

    for(const unsigned long long& val : visited) {
        timelineAmount += val;
    }

    std::cout << timelineAmount << std::endl;
}