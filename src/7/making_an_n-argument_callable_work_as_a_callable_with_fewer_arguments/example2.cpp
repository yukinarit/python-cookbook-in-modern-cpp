/// example.cpp
///
/// Using partial to supply extra arguments to a callback function

#include <functional>
#include <future>
#include <iostream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>

template <typename T>
void output_result(const T& result, std::reference_wrapper<std::ostream> os) {
    os.get() << fmt::format("Got: {}\n", result);
}

// A sample function
template <typename T>
T add(T x, T y) {
    return x + y;
}

// template <typename F, typename T = std::result_of_t<F>, typename Callback>
template <typename F, typename Callback>
void apply_async(F&& f, Callback&& cb) {
    auto result = async(std::launch::async, f).get();
    cb(result);
}

int main() {
    using namespace std::placeholders;
    using namespace std::string_literals;

    apply_async(std::bind(add<int>, 1, 1), std::bind(output_result<int>, _1, std::ref(std::cout)));

    // or using lambda
    auto& os = std::cout;
    apply_async([]() { return add("foo"s, "bar"s); },
                [&os](auto& v) { output_result(v, std::ref(os)); });

    return 0;
}
