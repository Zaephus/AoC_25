
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "TextHandler.h"

struct Vector2 {
    long long x = 0;
    long long y = 0;
};

inline std::vector<Vector2> processTextToVector2(const std::vector<std::string>& _lines) {
    std::vector<Vector2> positions;

    for(int i = 0; i < _lines.size(); i++) {
        int counter = 0;

        std::string line = _lines[i];

        positions.emplace_back();

        while(!line.empty()) {
            const long long pos = static_cast<long long>(line.find(','));

            std::string part;

            if(pos == std::string::npos) {
                part = line.substr(pos+1);
                line = "";
            }
            else {
                part = line.substr(0, pos);
                line = line.substr(pos+1);
            }

            const long long val = std::stoll(part);

            switch(counter) {
            case 0: positions[i].x = val; break;
            case 1: positions[i].y = val; break;
            default: break;
            }

            counter++;
        }
    }

    return positions;
}

inline void dayNine_PartOne() {
    const std::vector<Vector2> redTiles = processTextToVector2(TextHandler::loadFile("Day_9/day_9.txt"));

    long long area = 0;

    for(int i = 0; i < redTiles.size(); i++) {
        for(int j = i+1; j < redTiles.size(); j++) {
            const long long x = redTiles[i].x - redTiles[j].x + 1;
            const long long y = redTiles[i].y - redTiles[j].y + 1;

            const long long a = x * y;
            if(a > area) {
                area = a;
            }
        }
    }

    std::cout << "Area is " << area << std::endl;
}

inline void dayNine_PartTwo() {
    const std::vector<Vector2> redTiles = processTextToVector2(TextHandler::loadFile("Day_9/day_9.txt"));

    long long area = 0;

    for(int i = 0; i < redTiles.size(); i++) {
        for(int j = 0; j < redTiles.size(); j++) {
            if(i == j) { continue; }

            if(redTiles[i].x != redTiles[j].x) {
                continue;
            }

            for(int k = 0; k < redTiles.size(); k++) {
                if(k == j || k == i) { continue; }

                if(redTiles[k].y != redTiles[i].y && redTiles[k].y != redTiles[j].y) {
                    continue;
                }

                
            }
        }
    }

    std::cout << "Area is " << area << std::endl;
}