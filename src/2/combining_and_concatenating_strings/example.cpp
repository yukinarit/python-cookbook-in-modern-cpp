/// example.cpp
///
/// Example of combining text via generators

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

std::vector<std::string> sample() {
    // There is no coroutine yet in C++17 :(
    return {"Is", "Chicago", "Not", "Chicago?"};
}

std::vector<std::string> combine(const std::vector<std::string>& source, std::size_t maxsize) {
    std::vector<std::string> parts;
    std::ostringstream ss;
    for (auto& part : source) {
        ss << part;
        if (ss.str().size() > maxsize) {
            parts.push_back(ss.str());
            ss = std::ostringstream();
        }
    }

    parts.push_back(ss.str());
    return parts;
}

int main() {
    // (a) Simple join
    auto sample_data = sample();
    auto text = fmt::join(sample_data.begin(), sample_data.end(), "");
    fmt::print("{}\n", text);

    // (b) Redirection of parts to I/O
    for (auto& s : sample()) {
        fmt::print("{}", s);
    }
    fmt::print("\n");

    // (c) Combination of parts into buffers and larger I/O operations
    for (auto& s : combine(sample(), 5)) {
        fmt::print("{}", s);
    }
    fmt::print("\n");

    return 0;
}
