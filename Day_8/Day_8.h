
#pragma once

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "TextHandler.h"

struct Vector3 {
    long long x = 0;
    long long y = 0;
    long long z = 0;

    std::vector<int> connections;

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

struct Connection {
    int vecA = -1;
    int vecB = -1;

    long long dist = 0;
};

struct Circuit {
    std::vector<int> containingPositions;
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

inline int findConnections()

inline void dayEight_PartOne() {
    const std::vector<std::string> lines = TextHandler::loadFile("Day_8/day_8.txt");
    std::vector<Vector3> positions = processTextToVectors(lines);

    std::vector<Connection> connections;

    for(int i = 0; i < positions.size(); i++) {
        long long smallestDist = LLONG_MAX;
        int closestNeighbour = -1;

        for(int j = 0; j < positions.size(); j++) {
            if(i == j) { continue; }

            // Check if connection already exists
            bool conFound = false;
            for(const Connection& con : connections) {
                if((con.vecA == i && con.vecB == j) || (con.vecA == j && con.vecB == i)) {
                    conFound = true;
                    break;
                }
            }

            if(conFound) {
                continue;
            }

            const long long dist = positions[i].sqrDist(positions[j]);

            if(dist < smallestDist) {
                smallestDist = dist;
                closestNeighbour = j;
            }
        }

        if(closestNeighbour < 0) { std::cerr << "Somehow no closest neighbour was found!" << std::endl; }

        Connection connection;
        connection.vecA = i;
        connection.vecB = closestNeighbour;
        connection.dist = smallestDist;

        connections.push_back(connection);
    }

    std::vector<int> shortestConIndices;

    while(shortestConIndices.size() != 10) {
        int conIndex = -1;
        long long shortestDist = LLONG_MAX;

        for(int i = 0; i < connections.size(); i++) {
            if(std::count(shortestConIndices.begin(), shortestConIndices.end(), i) != 0) {
                continue;
            }

            if(connections[i].dist < shortestDist) {
                conIndex = i;
                shortestDist = connections[i].dist;
            }
        }

        shortestConIndices.push_back(conIndex);
    }

    std::cout << "Shortest connections: " << std::endl;
    for(int i = 0; i < shortestConIndices.size(); i++) {
        std::cout << connections[i].vecA << " - " << connections[i].vecB << ": " << connections[i].dist << std::endl;

        positions[connections[i].vecA].connections.push_back(connections[i].vecB);
        positions[connections[i].vecB].connections.push_back(connections[i].vecA);
    }

    std::vector<Circuit> circuits;

    for(int i = 0; i < positions.size(); i++) {

        for(const Circuit& circuit : circuits) {
            if()
        }
    }

}

inline void dayEight_PartTwo() {

}