
#pragma once

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