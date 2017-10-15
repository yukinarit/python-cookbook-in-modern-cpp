/// example.cpp
///
/// Example of a priority queue

#include <queue>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

using namespace ranges;

struct Item {
    template <typename STR>
    Item(STR&& str, int priority)
        : name(std::forward<std::string>(str))
        , priority(priority) {
    }
    std::string name;
    int priority = 0;
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return os << "Item(" << item.name << ")";
}

int main() {
    auto comparer = [](const auto& a, const auto& b) { return a.priority < b.priority; };
    std::priority_queue<Item, std::vector<Item>, decltype(comparer)> queue(comparer);

    queue.emplace("foo", 1);
    queue.emplace("bar", 5);
    queue.emplace("spam", 4);
    queue.emplace("grok", 1);

    fmt::print("Should be bar:{}\n", queue.top());
    queue.pop();
    fmt::print("Should be spam:{}\n", queue.top());
    queue.pop();
    fmt::print("Should be foo:{}\n", queue.top());
    queue.pop();
    fmt::print("Should be grok:{}\n", queue.top());
    queue.pop();

    return 0;
}
