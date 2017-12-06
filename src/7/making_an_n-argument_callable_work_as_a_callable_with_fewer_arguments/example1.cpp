/// example.cpp
///
/// Example of using partial() with sorting a list of (x,y) coordinates

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>

double hypot(double x, double y) {
    return std::sqrt(x * x + y * y);
}

template <typename T>
double distance(const std::tuple<T, T>& p1, const std::tuple<T, T>& p2) {
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    return hypot(x2 - x1, y2 - y1);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::tuple<T, T> t) {
    return os << fmt::format("({}, {})", std::get<0>(t), std::get<1>(t));
}

template <typename Container>
void pprint(Container&& items) {
    // FIX for clang6
    // std::cout << fmt::join(items.begin(), items.end(), ",");
}

int main() {
    std::tuple<int, int> pt{4, 3};
    std::vector<std::tuple<int, int>> points{
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 7},
    };
    std::sort(points.begin(), points.end(),
              [&pt](const auto& a, const auto& b) { return distance(pt, a) < distance(pt, b); });
    pprint(points);

    return 0;
}
