
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "TextHandler.h"

inline void dayFour_PartOne() {
    const std::vector<std::string> lines = TextHandler::loadFile("Day_4/day_4.txt");

    int accessibleRolls = 0;

    for(int l = 0; l < lines.size(); l++) {
        for(int c = 0; c < lines[l].length(); c++) {
            if(lines[l][c] == '.') {
                continue;
            }

            int neighbourRolls = 0;

            for(int x = c-1; x <= c+1; x++) {
                if(x < 0 || x >= lines[l].length()) {
                    continue;
                }

                for(int y = l-1; y <= l+1; y++) {
                    if((y == l && x == c) || y < 0 || y >= lines.size()) {
                        continue;
                    }

                    if(lines[y][x] == '@') {
                        neighbourRolls++;
                    }
                }
            }

            if(neighbourRolls < 4) {
                accessibleRolls++;
            }
        }
    }

    std::cout << accessibleRolls << std::endl;
}

inline void dayFour_PartTwo() {
    std::vector<std::string> lines = TextHandler::loadFile("Day_4/day_4.txt");
    std::vector<std::string> nextLines;

    int removedRolls = 0;

    bool canRemoveRolls = true;
    int removableRolls = 0;

    while(canRemoveRolls) {
        for(int l = 0; l < lines.size(); l++) {
            std::string nextLine;

            for(int c = 0; c < lines[l].length(); c++) {
                if(lines[l][c] == '.') {
                    nextLine += '.';
                    continue;
                }

                int neighbourRolls = 0;

                for(int x = c-1; x <= c+1; x++) {
                    if(x < 0 || x >= lines[l].length()) {
                        continue;
                    }

                    for(int y = l-1; y <= l+1; y++) {
                        if((y == l && x == c) || y < 0 || y >= lines.size()) {
                            continue;
                        }

                        if(lines[y][x] == '@') {
                            neighbourRolls++;
                        }
                    }
                }

                if(neighbourRolls < 4) {
                    removableRolls++;
                    nextLine += '.';
                }
                else {
                    nextLine += '@';
                }
            }

            nextLines.push_back(nextLine);
        }

        if(removableRolls == 0) {
            canRemoveRolls = false;
        }
        removedRolls += removableRolls;
        lines.swap(nextLines);
        nextLines.clear();
        removableRolls = 0;
    }

    std::cout << removedRolls << std::endl;
}