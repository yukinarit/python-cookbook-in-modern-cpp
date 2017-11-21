/// example.cpp
///
/// Iterating over merged sorted iterables

#include <iostream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <range/v3/all.hpp>

int main() {
    std::vector<int> a = {1, 4, 7, 10};
    std::vector<int> b = {2, 5, 6, 11};
    auto sorted = ranges::view::concat(a, b) | ranges::to_vector | ranges::action::sort;
    for (auto v : sorted) {
        fmt::print("{}\n", v);
    }

    return 0;
}
