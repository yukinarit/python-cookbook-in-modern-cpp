/// example.cpp
///
/// Remove duplicate entries from a sequence while keeping order

#include <iostream>
#include <set>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

using namespace ranges;

struct Item {
    std::string fname;
    std::string lname;
    int uid;
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return os << fmt::format("fname:'{}',lname:'{}',uid:{}", item.fname, item.lname, item.uid);
}

template <typename Container>
constexpr void pprint(Container&& items) {
    fmt::print("[");
    for (auto& v : items)
        fmt::print("{{{}}},\n", v);
    fmt::print("]\n");
}

int main() {
    std::vector<Item> rows = {{"Brian", "Jones", 1003},
                              {"David", "Beazley", 1002},
                              {"John", "Cleese", 1001},
                              {"Big", "Jones", 1004}};

    rows |= action::sort([](const Item& a, const Item& b) { return a.fname < b.fname; });
    fmt::print("Sorted by fname:\n");
    pprint(rows);

    rows |= action::sort([](const Item& a, const Item& b) { return a.lname < b.lname; });
    fmt::print("Sorted by lname:\n");
    pprint(rows);

    rows |= action::sort([](const Item& a, const Item& b) { return a.uid < b.uid; });
    fmt::print("Sorted by uid:\n");
    pprint(rows);

    return 0;
}
