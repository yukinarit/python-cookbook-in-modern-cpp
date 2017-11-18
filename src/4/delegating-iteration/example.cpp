/// example.cpp
///
/// Example of delegating iteration to an internal container

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

template <typename T>
struct Node {
    using Ptr = std::unique_ptr<Node<T>>;

    Node(T t)
        : value(t) {
    }
    T value;
    std::vector<Ptr> children;

    void add_child(Ptr&& child) {
        children.push_back(std::move(child));
    }

    auto begin() const {
        return children.begin();
    }

    auto end() const {
        return children.end();
    }
};

template <typename T>
using NodePtr = typename Node<T>::Ptr;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
    return os << "Node(" << node.value << ")";
}

int main() {
    auto root = std::make_unique<Node<int>>(0);
    auto child1 = std::make_unique<Node<int>>(1);
    auto child2 = std::make_unique<Node<int>>(2);
    root->add_child(std::move(child1));
    root->add_child(std::move(child2));

    for (auto& ch : *root) {
        fmt::print("{}\n", *ch);
    }

    return 0;
}
