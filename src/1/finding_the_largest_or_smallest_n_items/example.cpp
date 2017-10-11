/// example.cpp
///
/// Example of finding the N smallest or largest items

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

using namespace ranges;

struct Portfolio {
    std::string name = "";
    int share = 0;
    double price = 0.0;
};

std::ostream& operator<<(std::ostream& os, const Portfolio& p) {
    os << "{name:" << p.name << ",share:" << p.share << ",price:" << p.price << "}";
    return os;
}

int main() {
    std::vector<Portfolio> portfolio = {{"IBM", 100, 91.1},  {"AAPL", 50, 543.22},
                                        {"FB", 200, 21.09},  {"HPQ", 35, 31.75},
                                        {"YHOO", 45, 16.35}, {"ACME", 75, 115.65}};

    auto sorted = portfolio | move |
                  action::sort([](const auto& a, const auto& b) { return a.price < b.price; });
    // 3 cheapest
    for (auto& p : sorted | view::take(3)) {
        fmt::print("{} ", p);
    }
    fmt::print("\n");

    // 3 most expensive
    for (auto& p : sorted | view::reverse | view::take(3)) {
        fmt::print("{} ", p);
    }
    fmt::print("\n");

    return 0;
}
