
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "TextHandler.h"

struct Problem {
    std::vector<long long> values;
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

            const int val = std::stoi(part);

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
    const std::vector<std::string> lines = TextHandler::loadFile("Day_6/day_6.txt");

    std::vector<Problem> problems;
    int problemCount = 1;

    const long long length = static_cast<long long>(lines[0].length());

    for(long long j = length; j >= 0; j--) {
        std::string num;
        char op = ' ';
        for(std::string line : lines) {
            const char c = line[j];
            if(c == '+' || c == '*') {
                op = c;
            }
            else if(c != ' ' && c != '\0') {
                num += c;
            }
        }

        if(num.empty()) {
            problemCount++;
            continue;
        }

        if(problems.size() < problemCount) {
            problems.emplace_back();
        }

        const long long val = std::stoll(num);

        problems[problemCount-1].values.push_back(val);
        problems[problemCount-1].op = op;
    }

    long long total = 0;

    for(const Problem& problem : problems) {
        const long long result = problem.result();
        total += result;
    }

    std::cout << "Total is: " << total << std::endl;
}