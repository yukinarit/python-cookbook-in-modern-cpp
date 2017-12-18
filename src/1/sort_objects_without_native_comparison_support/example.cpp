/// example.cpp
///

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

struct User {
    int user_id{};
};

std::ostream& operator<<(std::ostream& os, const User& user) {
    return os << "User(" << user.user_id << ")";
}

#define attrgetter(name) [](const auto& a, const auto& b) { return a.name < b.name; }

int main() {
    std::vector<User> users{User{23}, User{3}, User{99}};
    std::sort(users.begin(), users.end(), attrgetter(user_id));
    for (auto& u : users) {
        fmt::print("{} ", u);
    };
    fmt::print("\n");
    return 0;
}
