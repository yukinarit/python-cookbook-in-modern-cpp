/// example.cpp
///
/// Find out what two dictionaries have in common

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include <fmt/format.h>
#include <range/v3/all.hpp>

using namespace ranges;

int main() {
    std::unordered_map<std::string, int> a = {{"x", 1}, {"y", 2}, {"z", 3}};
    decltype(a) b = {{"w", 10}, {"x", 11}, {"y", 2}};

    auto common_keys =
        a | view::keys | view::remove_if([&b](const auto& k) { return b.find(k) == b.end(); });
    fmt::print("Common keys: ");
    for (auto& key : common_keys) {
        fmt::print("{} ", key);
    }
    fmt::print("\n");

    auto keys_not_in_a =
        a | view::keys | view::remove_if([&b](const auto& k) { return b.find(k) != b.end(); });
    fmt::print("Keys in a not in b: ");
    for (auto& key : keys_not_in_a) {
        fmt::print("{} ", key);
    }
    fmt::print("\n");

    auto common_key_values = a | view::remove_if([&b](const auto& pair) {
                                 auto it = b.find(std::get<0>(pair));
                                 if (it == b.end())
                                     return true;
                                 if (std::get<1>(pair) != b[std::get<0>(pair)])
                                     return true;
                                 return false;
                             });
    fmt::print("(key,value) pairs in common: ");
    for (auto & [ key, value ] : common_key_values) {
        fmt::print("({}, {}) ", key, value);
    }
    fmt::print("\n");
    // print('(key,value) pairs in common:', a.items() & b.items())

    return 0;
}
