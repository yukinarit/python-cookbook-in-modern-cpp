/// example.cpp
///

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>

#include <fmt/format.h>
#include <range/v3/all.hpp>

// std::tuple<std::string, std::deque<std::string>&> search(std::ifstream& file,
//                                                         std::deque<std::string>& preflines,
//                                                         const std::string& pattern,
//                                                         int history = 1) {
std::tuple<std::string, std::deque<std::string>&> search(std::ifstream& file,
                                                         std::deque<std::string>& preflines,
                                                         const std::string& pattern,
                                                         int history = 1) {
    std::string line;
    return {line, preflines};
}

int main() {
    std::ifstream file("../somefile.txt");
    std::deque<std::string> prevlines;
    std::string pattern = "python";

    auto rv = search(file, prevlines, pattern);
    for (auto[line, plines] : rv) {
        if (line.empty())
            break;
        fmt::print("{}\n", line);
    }

    return 0;
}
