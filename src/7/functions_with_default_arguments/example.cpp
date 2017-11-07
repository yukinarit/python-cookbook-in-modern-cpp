/// example.cpp
///
/// Examples of a function with default arguments

#include <iostream>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

template <typename Container>
void pprint(Container&& items) {
    fmt::print("[{}]\n", fmt::join(items.begin(), items.end(), ","));
}

//# (b) Better alternative for mutable defaults
// def spam(b=None):
//    if b is None:
//        b = []
//    return b
//
// a = spam()
// print(a)
// a.append(1)
// a.append(2)
// b = spam()
// print(b)
// print('-'*10)

int main() {
    // (a) There is no equivalent in C++ to python mutable default argument
    //  but here is similar case in C++ by capturing container as reference.
    std::vector<int> v;
    auto spam = [&v]() -> decltype(auto) { return v; };

    auto& a = spam();
    pprint(a);
    a.emplace_back(1);
    a.emplace_back(2);
    auto& b = spam();
    pprint(b);

    return 0;
}
