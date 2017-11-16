/// example.cpp
///
/// Example of an object implementing both forward and reversed iterators

#include <iostream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <range/v3/all.hpp>

int main() {
    // Using range v3.
    fmt::print("Forward:\n");
    for (auto n : ranges::view::ints(1, 6)) {
        fmt::print("{}\n", n);
    }

    fmt::print("Reverse:\n");
    for (auto n : ranges::view::ints(1, 6) | ranges::view::reverse) {
        fmt::print("{}\n", n);
    }

    // Using iterator.
    std::vector<int> v{1, 2, 3, 4, 5};
    fmt::print("Forward:\n");
    for (auto it = v.begin(); it != v.end(); ++it) {
        fmt::print("{}\n", *it);
    }

    fmt::print("Reverse:\n");
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        fmt::print("{}\n", *it);
    }

    return 0;
}
