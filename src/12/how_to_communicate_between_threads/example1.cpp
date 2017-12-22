/// example.cpp
///

#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include <fmt/format.h>

using namespace std::chrono_literals;

constexpr int SENTINEL = INT_MAX;

int main() {
    std::queue<int> queue;
    std::mutex mutex;

    // A thread that produces data
    std::thread producer([&queue, &mutex]() {
        int n = 10;
        while (n > 0) {
            // Produce some data
            {
                std::lock_guard lock(mutex);
                fmt::print("put {}\n", n);
                queue.push(n);
            }
            --n;
            std::this_thread::sleep_for(2s);
        }
        {
            std::lock_guard lock(mutex);
            queue.push(SENTINEL);
        }
    });

    // A thread that consumes data
    std::thread consumer([&queue, &mutex]() {
        while (true) {
            // Get some data
            int data{};
            {
                if (queue.empty()) {
                    continue;
                }
                std::lock_guard lock(mutex);
                data = queue.front();
                queue.pop();

                // Check for termination
                if (data == SENTINEL) {
                    queue.push(SENTINEL);
                    break;
                }
            }

            // Process the data
            fmt::print("Got:{}\n", data);
        }
        std::cout << "Consumer shutting down\n";
    });

    producer.join();
    consumer.join();

    return 0;
}
