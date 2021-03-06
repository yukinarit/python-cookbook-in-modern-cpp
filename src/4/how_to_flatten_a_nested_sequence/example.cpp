/// example.cpp
///
/// Remove duplicate entries from a sequence while keeping order

#include <array>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

using namespace ranges;

template <typename Test, template <typename...> class Ref>
struct is_specialization : std::false_type {};

template <template <typename...> class Ref, typename... Args>
struct is_specialization<Ref<Args...>, Ref> : std::true_type {};

template <typename T>
decltype(auto) flatten(const std::vector<T>& items) {
    auto rng = items | view::for_each([](const auto& sub_items) {
                   using value_type = typename std::decay_t<decltype(sub_items)>::value_type;
                   if
                       constexpr(is_specialization<value_type, std::vector>::value) {
                           return flatten(sub_items);
                       }
                   else {
                       return view::all(sub_items);
                   }
               });
    return rng;
}

std::vector<int> naive_flatten(const std::vector<std::vector<std::vector<int>>>& items) {
    std::vector<int> flattened;
    for (auto& i : items) {
        for (auto& j : i) {
            for (auto& k : j) {
                flattened.push_back(k);
            }
        }
    }

    return flattened;
}

int main() {
    std::vector<std::vector<std::vector<int>>> items = {
        {{1}}, {{2}}, {{3}, {4}, {5, 6}, {7}}, {{8}}, {{9}}};

    auto rng = flatten(items);
    // auto rng = naive_flatten(items);
    for (auto& n : rng) {
        fmt::print("{}\n", n);
    }

    return 0;
}
