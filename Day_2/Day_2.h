
#pragma once

#include <cstring>
#include <string>
#include <vector>

inline void DayTwo() {
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