
#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "TextHandler.h"

struct Vector3 {
    long long x = 0;
    long long y = 0;
    long long z = 0;

    std::vector<Vector3> connections;

    [[nodiscard]] long long sqrMag() const {
        return x*x + y*y + z*z;
    }

    [[nodiscard]] long long sqrDist(const Vector3& _v) const {
        const long long compX = x - _v.x;
        const long long compY = y - _v.y;
        const long long compZ = z - _v.z;

        return compX*compX + compY*compY + compZ*compZ;
    }

    bool operator==(const Vector3& _v) const {
        return x == _v.x && y == _v.y && z == _v.z;
    }

    bool operator!=(const Vector3& _v) const {
        return this != &_v;
    }
};

inline std::vector<Vector3> processTextToVectors(const std::vector<std::string>& _lines) {
    std::vector<Vector3> positions;

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
                case 2: positions[i].z = val; break;
                default: break;
            }

            counter++;
        }
    }

    return positions;
}

inline void dayEight_PartOne() {
    const std::vector<std::string> lines = TextHandler::loadFile("Day_8/day_8.txt");
    std::vector<Vector3> positions = processTextToVectors(lines);

    for(int i = 0; i < positions.size(); i++) {
        long long smallestDist = LLONG_MAX;
        int closestNeighbour = -1;

        for(int j = 0; j < positions.size(); j++) {
            if(i == j) { continue; }

            if(std::count(positions[i].connections.begin(), positions[i].connections.end(), positions[j]) != 0) {
                continue;
            }

            const long long dist = positions[i].sqrDist(positions[j]);

            if(dist < smallestDist) {
                smallestDist = dist;
                closestNeighbour = j;
            }
        }

        if(closestNeighbour < 0) { std::cerr << "Somehow no closest neighbour was found!" << std::endl; }

        positions[closestNeighbour].connections.push_back(positions[i]);
        positions[i].connections.push_back(positions[closestNeighbour]);
    }

    for(const Vector3& vec : positions) {
        std::cout << vec.x << ", " << vec.y << ", " << vec.z << std::endl;
        std::cout << " Connection amount: " << vec.connections.size() << std::endl;
        std::cout << " Connected with:" << std::endl;

        for(const Vector3& con : vec.connections) {
            std::cout << " " << con.x << ", " << con.y << ", " << con.z << std::endl;
        }
    }
}

inline void dayEight_PartTwo() {

}