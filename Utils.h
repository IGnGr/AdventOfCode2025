#pragma once

#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

std::string repeatString(std::string s, int n) {
    std::ostringstream os;
    for (int i = 0; i < n; i++)
        os << s;
    return os.str();
}