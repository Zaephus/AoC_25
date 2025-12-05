
#pragma once

#include <cmath>
#include <string>
#include <vector>

#include "TextHandler.h"

inline void dayThree_PartOne() {
    const std::vector<std::string> banks = TextHandler::loadFile("Day_3/day_3.txt");

    int totalJoltage = 0;

    for(std::string bank : banks) {
        int firstDigit = 0;
        int firstDigitLocation = 0;

        for(int i = 0; i < bank.size()-1; i++) {
            int num = bank[i] - '0';
            if(num > firstDigit) {
                firstDigit = num;
                firstDigitLocation = i;
            }
        }

        int secondDigit = 0;

        for(int i = firstDigitLocation+1; i < bank.size(); i++) {
            int num = bank[i] - '0';
            if(num > secondDigit) {
                secondDigit = num;
            }
        }

        const int bankJoltage = 10*firstDigit + secondDigit;

        totalJoltage += bankJoltage;
    }

    std::cout << totalJoltage << std::endl;
}

inline void dayThree_PartTwo() {
    const std::vector<std::string> banks = TextHandler::loadFile("Day_3/day_3.txt");

    unsigned long long totalJoltage = 0;

    for(std::string bank : banks) {
        unsigned long long bankJoltage = 0;
        int startIndex = 0;

        for(int i = 11; i >= 0; i--) {
            int digit = 0;
            for(int j = startIndex; j < bank.length() - i; j++) {
                int num = bank[j] - '0';
                if(num > digit) {
                    digit = num;
                    startIndex = j+1;
                }
            }

            const unsigned long long joltage = digit * std::pow(10, i);
            bankJoltage += joltage;
        }

        totalJoltage += bankJoltage;
    }

    std::cout << totalJoltage << std::endl;
}