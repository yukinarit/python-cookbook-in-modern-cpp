/// example.cpp
///
/// Examples of *args and **kwargs functions

#include <chrono>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

using namespace std::chrono_literals;

template <typename F, typename... Args>
void timethis(F&& f, Args&&... args) {
    std::chrono::high_resolution_clock::time_point start(std::chrono::high_resolution_clock::now());
    if constexpr (sizeof...(args) > 0) {
        std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
    } else {
        f();
    }
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Elapsed: "
              << std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count()
              << "msec.\n";
}

void func(int seconds) {
    std::cout << "Start!!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "End!!\n";
}

void free_function() {
    std::cout << "This is free function!\n";
}

class A {
public:
    void instance_method() {
        std::cout << "This is instance method!\n";
    }
    static void class_method() {
        std::cout << "This is class method!\n";
    }
};

#define DECORATE(func, wrapper, name)                                                              \
    template <typename... Args>                                                                    \
    void name(Args... args) {                                                                      \
        wrapper(func, std::forward<Args>(args)...);                                                \
    }

DECORATE(func, timethis, time_func)
DECORATE(free_function, timethis, time_free_function)
DECORATE(A::class_method, timethis, time_class_method)

int main() {
    time_func(2);
    time_free_function();
    time_class_method();
    return 0;
}
