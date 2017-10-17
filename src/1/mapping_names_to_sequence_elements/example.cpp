/// example.cpp
///

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include <fmt/format.h>
#include <range/v3/all.hpp>

using namespace ranges;

struct Stock {
    std::string name;
    int shares = 0;
    double price = 0.0;
};

double computeCost(const std::vector<std::tuple<std::string, int, double>>& records) {
    double total = 0.0;
    for (auto& rec : records) {
        Stock s{std::get<0>(rec), std::get<1>(rec), std::get<2>(rec)};
        total += (s.shares * s.price);
    }
    return total;
}

int main() {
    std::vector<std::tuple<std::string, int, double>> records = {
        {"GOOG", 100, 490.1}, {"ACME", 100, 123.45}, {"IBM", 50, 91.15}};

    fmt::print("{}\n", computeCost(records));

    return 0;
}
