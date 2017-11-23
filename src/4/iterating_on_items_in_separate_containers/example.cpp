/// example.cpp
///
/// Example of iterating over two sequences as one

#include <iostream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <range/v3/all.hpp>

int main() {
    std::vector<int> a = {1, 4, 7, 10};
    std::vector<int> b = {2, 5, 6, 11};
    for (auto v : ranges::view::concat(a, b)) {
        fmt::print("{}\n", v);
    }

    return 0;
}
