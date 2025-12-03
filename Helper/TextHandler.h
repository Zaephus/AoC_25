
#pragma once

#include <string>
#include <vector>

class TextHandler {
    public:
        static std::vector<std::string> loadFile(const std::string& _path, const char& _delimiter = '\n');
};