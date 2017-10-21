/// example.cpp
///
/// Remove duplicate entries from a sequence while keeping order

#include <iostream>
#include <set>
#include <vector>

#include <fmt/format.h>
#include <range/v3/all.hpp>

using namespace ranges;

template <typename Container>
constexpr auto dedupe(const Container& items, std::set<typename Container::value_type>& seen)
    -> decltype(auto) {
    auto rng = items | view::remove_if([&](auto v) {
                   if (seen.end() == seen.find(v)) {
                       seen.emplace(v);
                       return false;
                   } else {
                       return true;
                   }
               });
    return rng;
}

template <typename Container>
constexpr void print(Container&& items) {
    for (auto& v : items)
        fmt::print("{} ", v);
    fmt::print("\n");
}

int main() {

    std::vector<int> items = {1, 5, 2, 1, 9, 1, 5, 10};
    std::set<int> seen;

    print(items);
    // Needs to pass seen variable because Range view is lazy evaluation.
    print(dedupe(items, seen));
    return 0;
}
