/// example.cpp
///
/// Example of calculating with dictionaries

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include <fmt/format.h>
#include <range/v3/all.hpp>

using namespace ranges;

int main() {
    std::unordered_map<std::string, double> prices = {
        {"ACME", 45.23}, {"AAPL", 612.78}, {"IBM", 205.55}, {"HPQ", 37.20}, {"FB", 10.75},
    };

    // Find min and max price
    auto min_it = std::min_element(prices.begin(), prices.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    fmt::print("min price: ({}, {})\n", (*min_it).second, (*min_it).first);
    auto max_it = std::max_element(prices.begin(), prices.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    fmt::print("max price: ({}, {})\n", (*max_it).second, (*max_it).first);

    fmt::print("sorted prices:\n");
    auto sorted =
        prices | view::transform([](const auto& v) { return std::tuple(v.first, v.second); }) |
        to_vector |
        action::sort([](const auto& a, const auto& b) { return std::get<1>(a) < std::get<1>(b); });
    for (const auto & [ name, price ] : sorted) {
        fmt::print("     {} {}\n", name, price);
    }

    return 0;
}
