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
    int n = 0;
    auto f = [&]() { fmt::print("n={}\n", n); };
    auto f_setn = [&](int new_n) { n = new_n; };
    auto f_getn = [&]() { return n; };

    f();
    n = 0;
    f_setn(10);
    f();
    fmt::print("{}\n", f_getn());

    return 0;
}
