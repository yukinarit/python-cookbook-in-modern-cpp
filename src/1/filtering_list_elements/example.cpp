/// example.cpp
///
/// Examples of different ways to filter data

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include <fmt/format.h>
#include <range/v3/all.hpp>

using namespace ranges;

int main() {
    std::vector<int> mylist = {1, 4, -5, 10, -7, 2, 3, -1};

    // All positive values
    auto rng = mylist | view::remove_if([](const auto& v) { return v <= 0; });
    for (auto& v : rng) {
        fmt::print("{} ", v);
    }
    fmt::print("\n");

    // All negative values
    auto negative_rng = mylist | view::remove_if([](const auto& v) { return v >= 0; });
    for (auto& v : negative_rng) {
        fmt::print("{} ", v);
    }
    fmt::print("\n");

    // Negative values clipped to 0
    auto clipped_negative_rng =
        mylist | view::transform([](auto& v) { return std::max(0, v); }) | to_vector;
    for (auto& v : clipped_negative_rng) {
        fmt::print("{} ", v);
    }
    fmt::print("\n");

    // Positive values clipped to 0
    auto clipped_positive_rng =
        mylist | view::transform([](auto& v) { return std::min(0, v); }) | to_vector;
    for (auto& v : clipped_positive_rng) {
        fmt::print("{} ", v);
    }
    fmt::print("\n");

    // Compressing example
    std::vector<std::string> addresses = {
        "5413 N CLARK",      "5148 N CLARK",   "5800 E 58TH",     "2122 N CLARK",
        "5645 N RAVENSWOOD", "1060 W ADDISON", "4801 N BROADWAY", "1039 W GRANVILLE",
    };

    std::vector<int> counts = {0, 3, 10, 4, 1, 7, 6, 1};
    auto compressed = view::zip(counts, addresses) | view::remove_if([](const auto& t) {
                          return std::get<0>(t) <= 5;

                      });
    for (auto[c, a] : compressed) {
        fmt::print("{} ", a);
    }
    fmt::print("\n");

    return 0;
}
