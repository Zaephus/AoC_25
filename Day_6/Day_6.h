
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "TextHandler.h"

struct Problem {
    std::vector<int> values;
    char op = ' ';

    [[nodiscard]] long long result() const {
        long long total = values[0];

        switch(op) {
            case '+':
                for(int i = 1; i < values.size(); i++) {
                    total += values[i];
                }
                break;
            case '*':
                for(int i = 1; i < values.size(); i++) {
                    total *= values[i];
                }
                break;
            default:
                break;
        }

        return total;
    }
};

inline void daySix_PartOne() {
    const std::vector<std::string> lines = TextHandler::loadFile("Day_6/day_6.txt");

    std::vector<Problem> problems;

    for(int i = 0; i < 4; i++) {
        std::string line = lines[i];

        int problemCount = 0;

        while(!line.empty()) {
            const unsigned long long pos = line.find(' ');

            std::string part;

            if(pos == std::string::npos) {
                part = line;
                line = "";
            }
            else {
                part = line.substr(0, pos);
                line = line.substr(pos+1);
            }

            if(part.empty() || std::strcmp(part.c_str(), " ") == 0) {
                continue;
            }

            problemCount++;

            int val = std::stoi(part);

            if(problems.size() < problemCount) {
                problems.emplace_back();
            }

            problems[problemCount-1].values.push_back(val);
        }
    }

    std::string line = lines[4];

    int problemCount = 0;

    while(!line.empty()) {
        const unsigned long long pos = line.find(' ');

        std::string part;

        if(pos == std::string::npos) {
            part = line;
            line = "";
        }
        else {
            part = line.substr(0, pos);
            line = line.substr(pos+1);
        }

        if(part.empty() || std::strcmp(part.c_str(), " ") == 0) {
            continue;
        }

        problemCount++;

        const char op = part.c_str()[0];
        problems[problemCount-1].op = op;
    }

    long long total = 0;

    for(const Problem& problem : problems) {
        const long long result = problem.result();
        total += result;
    }

    std::cout << "Total is: " << total << std::endl;
}

inline void daySix_PartTwo() {

}