/// example.cpp
///

#include <iostream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <range/v3/all.hpp>

auto frange(int from, int to, double step) {
    double cur = 0.0;
    return ranges::view::generate([cur, step]() mutable {
               cur += step;
               return cur - step;
           }) |
           ranges::view::take_while([to](double v) { return v < to; });
};

int main() {
    for (auto n : frange(0, 4, 0.5)) {
        fmt::print("{}\n", n);
    }

    return 0;
}
