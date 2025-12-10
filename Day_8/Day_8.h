
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
    int junctionA = -1;
    int junctionB = -1;

    Connection() {
        junctionA = -1;
        junctionB = -1;
    }
    Connection(const int _a, const int _b) {
        junctionA = _a;
        junctionB = _b;
    }
};

struct Circuit {
    std::vector<int> junctions;

    [[nodiscard]] bool contains(const int _index) const {
        for(const int& junction : junctions) {
            if(junction == _index) {
                return true;
            }
        }

        return false;
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

    std::cout << "Parsing positions" << std::endl;
    const std::vector<Vector3> positions = processTextToVectors(TextHandler::loadFile("Day_8/day_8.txt"));

    std::cout << "Finding connections" << std::endl;
    std::map<long long, Connection> connections;

    for(int i = 0; i < positions.size(); i++) {
        for(int j = i+1; j < positions.size(); j++) {
            long long dist = positions[i].sqrDist(positions[j]);

            if(connections.contains(dist)) {
                std::cout << "Already contained" << std::endl;
                dist++;
            }

            const Connection con(i, j);
            connections[dist] = con;
        }
    }

    connections.erase(std::next(connections.begin(), 1000), connections.end());

    std::cout << "Making circuits" << std::endl;
    std::vector<Circuit> circuits;

    for(auto [dist, con] : connections) {
        bool addedToExistingCircuit = false;

        int circuitContainingA = -1;
        int circuitContainingB = -1;

        for(int i = 0; i < circuits.size(); i++) {
            if(circuits[i].contains(con.junctionA) && circuits[i].contains(con.junctionB)) {
                addedToExistingCircuit = true;
                break;
            }

            if(circuits[i].contains(con.junctionA)) {
                circuitContainingA = i;
                addedToExistingCircuit = true;
            }

            if(circuits[i].contains(con.junctionB)) {
                circuitContainingB = i;
                addedToExistingCircuit = true;
            }
        }

        if(addedToExistingCircuit) {
            if(circuitContainingA != -1 && circuitContainingB == -1) {
                circuits[circuitContainingA].junctions.push_back(con.junctionB);
            }
            if(circuitContainingB != -1 && circuitContainingA == -1) {
                circuits[circuitContainingB].junctions.push_back(con.junctionA);
            }
            if(circuitContainingA != -1 && circuitContainingB != -1) {
                if(circuits[circuitContainingA].junctions.size() >= circuits[circuitContainingB].junctions.size()) {
                    for(const int& junctionInB : circuits[circuitContainingB].junctions) {
                        circuits[circuitContainingA].junctions.push_back(junctionInB);
                    }
                    circuits.erase(circuits.begin() + circuitContainingB);
                }
                else {
                    for(const int& junctionInA : circuits[circuitContainingA].junctions) {
                        circuits[circuitContainingB].junctions.push_back(junctionInA);
                    }
                    circuits.erase(circuits.begin() + circuitContainingA);
                }
            }
        }
        else {
            Circuit circuit;
            circuit.junctions.push_back(con.junctionA);
            circuit.junctions.push_back(con.junctionB);

            circuits.push_back(circuit);
        }
    }

    std::cout << "Finding three largest circuits" << std::endl;

    std::vector<int> largestCircuits;

    while(largestCircuits.size() != 3) {
        int largestCircuitIndex;
        int largestSize = 0;

        for(int i = 0; i < circuits.size(); i++) {
            if(std::count(largestCircuits.begin(), largestCircuits.end(), i) != 0) { continue; }

            if(circuits[i].junctions.size() > largestSize) {
                largestSize = circuits[i].junctions.size();
                largestCircuitIndex = i;
            }
        }

        largestCircuits.push_back(largestCircuitIndex);
    }

    std::cout << "Calculating total" << std::endl;
    long long total = 1;

    for(const int largestCircuit : largestCircuits) {
        const long long size = static_cast<long long>(circuits[largestCircuit].junctions.size());
        total *= size;
    }

    std::cout << "Total is: " << total << std::endl;

    // std::cout << std::endl << "Circuits after processing:" << std::endl;
    // for(const Circuit& c : circuits) {
    //     std::cout << " contains:" << std::endl;
    //     for(const int& i : c.junctions) {
    //         std::cout << "  " << i << std::endl;
    //     }
    //     std::cout << std::endl;
    // }
}

inline void dayEight_PartTwo() {

}