/// example.cpp
///
/// Determine the most common words in a list

#include <algorithm>
#include <iostream>
#include <unordered_map>

#include <fmt/format.h>
#include <range/v3/all.hpp>

using namespace ranges;

int main() {
    std::vector<std::string> words{
        "look",   "into", "my",   "eyes", "look", "into",   "my",   "eyes",   "the",   "eyes",
        "the",    "eyes", "the",  "eyes", "not",  "around", "the",  "eyes",   "don't", "look",
        "around", "the",  "eyes", "look", "into", "my",     "eyes", "you're", "under"};

    std::vector<std::tuple<std::string, std::size_t>> counted;
    auto grouped =
        action::sort(words) | view::group_by([](const auto& a, const auto& b) { return a == b; });
    for_each(grouped, [&counted](auto rng) { counted.emplace_back(*rng.begin(), distance(rng)); });

    auto sorted =
        action::sort(counted, [](auto& l, auto& r) { return std::get<1>(l) > std::get<1>(r); });
    auto most_common3 = sorted | view::take(3);

    for (auto & [ word, count ] : most_common3) {
        fmt::print("({}, count={})\n", word, count);
    }

    return 0;
}
