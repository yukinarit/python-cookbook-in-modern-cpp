/// example.cpp
///
/// Examples of *args and **kwargs functions

#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

using namespace ranges;
using namespace std::string_literals;
template <typename T, typename U>
struct KeyValue {
    T key{};
    U value{};
};

template <typename T, typename... Args>
constexpr auto avg(T first, Args... rest) {
    return (double(first) + ... + double(rest)) / (1 + sizeof...(rest));
}

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const KeyValue<T, U>& kv) {
    return os << " " << kv.key << "=\"" << kv.value << "\"";
}

template <typename... Args>
std::string make_element(const std::string& name, const std::string& value, Args&&... args) {
    std::ostringstream ss;
    (ss << ... << args);
    return fmt::format("<{0}{2}>{1}</{0}>", name, value, ss.str());
}

int main() {
    fmt::print("{}\n", avg(1, 2));
    fmt::print("{}\n", avg(1, 2, 3, 4));

    fmt::print("{}\n", make_element("item", "Albatross",
                                    KeyValue<std::string, std::string>{"size", "large"},
                                    KeyValue<std::string, int>{"quantity", 6}));
    fmt::print("{}\n", make_element("p", "<spam>"));

    return 0;
}
