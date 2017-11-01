/// example.cpp
///
/// examples of keyword-only argument functions

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <optional>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

void recv(int maxsize, bool block = true) {
    fmt::print("{} {}\n", maxsize, block);
}

struct Block {
    bool value = true;
};

void recv(int maxsize, Block block) {
    fmt::print("{} {}\n", maxsize, block.value);
}

int minimum(std::initializer_list<int> list, std::optional<int> clip = std::nullopt) {
    auto m = std::min(list);
    if (clip) {
        m = clip.value() > m ? clip.value() : m;
    }
    return m;
}

int main() {
    // There is no keyword argument in C++
    // So we have to write like this
    recv(8192, false);

    // Or we can define a struct and write this way
    recv(8192, Block{false});

    fmt::print("{}\n", minimum({1, 5, 2, -5, 10}));
    fmt::print("{}\n", minimum({1, 5, 2, -5, 10}, 0));

    return 0;
}
