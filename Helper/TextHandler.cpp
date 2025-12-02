
#include "TextHandler.h"

#include <fstream>
#include <iostream>

std::vector<std::string> TextHandler::loadFile(const std::string& _path) {
    std::vector<std::string> lines;

    std::ifstream file("../" + _path);

    if(!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return lines;
    }

    std::string line;

    while(std::getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}