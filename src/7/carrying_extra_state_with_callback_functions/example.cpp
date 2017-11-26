/// example.cpp
///
/// This example is about the problem of carrying extra state around
/// through callback functions.   To test the examples, this very
/// simple code emulates the typical control of a callback.

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>
#include <range/v3/all.hpp>

using namespace ranges;
using namespace std::string_literals;
using namespace std::placeholders;

template <typename F, typename Callback, typename... Args>
void apply_async(F&& f, Callback&& cb, Args&&... args) {
    // Compute the result
    auto result = f(args...);

    // Invoke the callback with the result
    cb(result);
}

// A simple function for testing
template <typename T>
T add(const T& x, const T& y) {
    return x + y;
}

// A simple callback example
template <typename T>
void print_result(const T& result) {
    fmt::print("Got:{}\n", result);
}

class ResultHandler {
public:
    template <typename T>
    void handler(const T& result) {
        sequence += 1;
        fmt::print("[{}] Got: {}\n", sequence, result);
    }

    int sequence = 0;
};

struct SequenceNo {
    int sequence = 0;
};

template <typename T>
void handler_func(const T& result, SequenceNo& seq) {
    seq.sequence += 1;
    fmt::print("[{}] Got: {}\n", seq.sequence, result);
}

int main() {
    fmt::print("# --- A simple callback example\n");
    apply_async(add<int>, print_result<int>, 2, 3);
    apply_async(add<std::string>, print_result<std::string>, "hello"s, "world"s);

    fmt::print("# --- Using a bound method\n");
    ResultHandler r;
    apply_async(add<int>, std::bind(&ResultHandler::handler<int>, &r, _1), 2, 3);
    apply_async(add<std::string>, std::bind(&ResultHandler::handler<std::string>, &r, _1), "hello"s,
                "world"s);

    fmt::print("# --- Using a closure\n");
    int sequence = 0;
    auto handler = [&sequence](const auto& result) {
        sequence += 1;
        fmt::print("[{}] Got: {}\n", sequence, result);
    };
    apply_async(add<int>, handler, 2, 3);
    apply_async(add<std::string>, handler, "hello"s, "world"s);

    fmt::print("# --- Using a coroutine\n");
    fmt::print("coroutine is not yet supported in C++ :( \n");

    fmt::print("# --- Partial function application\n");
    SequenceNo seq;
    apply_async(add<int>, std::bind(handler_func<int>, _1, seq), 2, 3);

    return 0;
}
