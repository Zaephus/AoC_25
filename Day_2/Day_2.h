
#pragma once

#include <cstring>
#include <sstream>
#include <string>
#include <vector>

inline void dayTwo_PartOne() {
    const std::vector<std::string> ids = TextHandler::loadFile("Day_2/day_2.txt", ',');

    long long counter = 0;

    for(const std::string& id : ids) {
        const unsigned long long pos = id.find('-');

        if(pos == std::string::npos) {
            std::cerr << "Invalid id: " << id << std::endl;
            return;
        }

        const long long start = std::stoll(id.substr(0, pos));
        const long long end = std::stoll(id.substr(pos+1));

        for(long long i = start; i <= end; i++) {
            std::string s = std::to_string(i);

            const unsigned long long length = s.length();

            if(length % 2 != 0) {
                continue;
            }

            std::string a = s.substr(0, length/2);
            std::string b = s.substr(length/2);

            if(std::strcmp(a.c_str(), b.c_str()) == 0) {
                counter += i;
            }
        }
    }

    std::cout << counter << std::endl;
}

inline void dayTwo_PartTwo() {
    const std::vector<std::string> ids = TextHandler::loadFile("Day_2/day_2.txt", ',');

    long long counter = 0;

    for(const std::string& id : ids) {
        const unsigned long long pos = id.find('-');

        if(pos == std::string::npos) {
            std::cerr << "Invalid id: " << id << std::endl;
            return;
        }

        const long long start = std::stoll(id.substr(0, pos));
        const long long end = std::stoll(id.substr(pos+1));

        for(long long i = start; i <= end; i++) {
            std::string s = std::to_string(i);

            const unsigned long long length = s.length();

            for(int j = 2; j < length+1; j++) {
                if(length % j != 0) {
                    continue;
                }

                const int subLength = length / j;

                bool match = true;

                std::string firstPart = s.substr(0, subLength);

                for(int k = 1; k < j; k++) {
                    std::string nextPart = s.substr(k*subLength, subLength);
                    if(std::strcmp(firstPart.c_str(), nextPart.c_str()) != 0) {
                        match = false;
                        break;
                    }
                }

                if(match) {
                    counter += i;
                    break;
                }
            }
        }
    }

    std::cout << counter << std::endl;
}