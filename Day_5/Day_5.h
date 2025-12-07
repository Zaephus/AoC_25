
#pragma once

#include <cstring>
#include <map>
#include <string>
#include <vector>

#include "TextHandler.h"

inline void dayFive_PartOne() {
    std::vector<std::string> rangeTexts = TextHandler::loadFile("Day_5/day_5.txt");
    std::vector<std::string> ingredients;

    // Separates ingredients list from id ranges in input.
    for(int i = 0; i < rangeTexts.size(); i++) {
        if(rangeTexts[i].empty()) {
            ingredients.assign(rangeTexts.begin() + i + 1, rangeTexts.end());
            rangeTexts.erase(rangeTexts.begin() + i, rangeTexts.end());
            rangeTexts.shrink_to_fit();
            break;
        }
    }

    std::map<long long, long long> ranges;

    // Separates the id ranges from the input into a map.
    for(const std::string& range : rangeTexts) {
        const unsigned long long pos = range.find('-');

        if(pos == std::string::npos) {
            std::cerr << "Invalid id: " << range << std::endl;
            return;
        }

        const long long start = std::stoll(range.substr(0, pos));
        const long long end = std::stoll(range.substr(pos+1));

        // Checks if another range key is already present, continues if the value is larger than the new value
        if(ranges.contains(start)) {
            if(ranges.at(start) >= end) {
                continue;
            }
        }

        ranges[start] = end;
    }

    unsigned int freshCount = 0;

    // Checks for freshness
    for(const std::string& ingredient : ingredients) {
        const long long num = std::stoll(ingredient);

        for(const std::pair<long long, long long> range : ranges) {
            if(num >= range.first && num <= range.second) {
                freshCount++;
                break;
            }
        }
    }

    std::cout << freshCount << std::endl;
}

inline void dayFive_PartTwo() {
    std::vector<std::string> rangeTexts = TextHandler::loadFile("Day_5/day_5.txt");

    // Removes ingredients list from id ranges in input.
    for(int i = 0; i < rangeTexts.size(); i++) {
        if(rangeTexts[i].empty()) {
            rangeTexts.erase(rangeTexts.begin() + i, rangeTexts.end());
            rangeTexts.shrink_to_fit();
            break;
        }
    }

    std::map<long long, long long> ranges;

    // Separates the id ranges from the input into a map.
    for(const std::string& rangeText : rangeTexts) {
        const unsigned long long pos = rangeText.find('-');

        if(pos == std::string::npos) {
            std::cerr << "Invalid id: " << rangeText << std::endl;
            return;
        }

        long long start = std::stoll(rangeText.substr(0, pos));
        const long long end = std::stoll(rangeText.substr(pos+1));

        // Checks if another range key is already present, continues if the value is larger than the new value
        if(ranges.contains(start)) {
            if(ranges.at(start) >= end) {
                continue;
            }
        }

        ranges[start] = end;
    }

    std::map<long long, long long> processedRanges;

    // Processes the ranges so overlapping ranges are combined
    for(std::pair<long long, long long> range : ranges) {
        bool skipRange = false;

        for(const std::pair<long long, long long> comp : processedRanges) {
            if(range.first >= comp.first && range.first <= comp.second) {
                if(range.second > comp.second) {
                    range.first = comp.first;
                    break;
                }

                skipRange = true;
                break;
            }
        }

        if(!skipRange) {
            processedRanges[range.first] = range.second;
        }
    }

    unsigned long long freshCount = 0;

    for(const std::pair<long long, long long> range : processedRanges) {
        freshCount += range.second - range.first + 1;
    }

    std::cout << "Fresh count: " << freshCount << std::endl;
}