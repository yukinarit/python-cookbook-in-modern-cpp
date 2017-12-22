/// example.cpp
///

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <tuple>
#include <vector>

#include <fmt/format.h>
#include <fmt/ostream.h>

using namespace std::chrono_literals;

template <typename T, typename Compare>
class ThreadSafePQueue {
public:
    template <typename F>
    ThreadSafePQueue(F&& f)
        : m_queue(std::forward<F>(f)) {
    }
    void put(T&& value) {
        {
            std::lock_guard lock(m_mutex);
            m_queue.emplace(std::forward<T>(value));
            ++m_count;
        }
        m_cv.notify_one();
    }

    T get() {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [&]() { return m_count > 0; });
        auto v = m_queue.top();
        m_queue.pop();
        return v;
    }

private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::priority_queue<T, std::vector<T>, Compare> m_queue;
    std::size_t m_count{};
};

int main() {
    using value_t = std::tuple<std::string, int>;

    auto compare = [](auto& t1, auto& t2) -> bool { return std::get<1>(t1) < std::get<1>(t2); };
    ThreadSafePQueue<value_t, decltype(compare)> q(compare);
    std::thread producer([&q]() {
        fmt::print("Producing items");
        q.put(value_t("C", 5));
        q.put(value_t("A", 15));
        q.put(value_t("B", 10));
        q.put(value_t("D", 0));
        q.put(value_t("", -100));
    });

    std::thread consumer([&q]() {
        std::this_thread::sleep_for(5s);
        fmt::print("Getting items\n");
        while (true) {
            auto item = q.get();
            if (std::get<0>(item).empty())
                break;
            fmt::print("Got:({},{})\n", std::get<0>(item), std::get<1>(item));
        }
        fmt::print("Consumer done\n");
    });

    producer.join();
    consumer.join();

    return 0;
}
