/// example.cpp
///

#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

#include <fmt/format.h>

using namespace std::chrono_literals;

class Context {
public:
    explicit Context(int id)
        : id(id) {
    }
    int id{};
};

struct Task {
    using Ptr = std::shared_ptr<Task>;

    template <typename F>
    Task(F&& f)
        : f(std::forward<F>(f)) {
    }

    void run(Context& ctx) {
        f(ctx);
    }

    std::function<void(Context& ctx)> f;
};
using TaskPtr = Task::Ptr;

class Thread {
public:
    using Ptr = std::unique_ptr<Thread>;
    Thread(int id)
        : m_context(id) {
        m_thread.reset(new std::thread([&]() {
            {
                std::lock_guard lock(m_mutex);
                m_running = true;
            }

            while (m_running) {
                printf("Waiting for new tasks %d\n", m_context.id);
                std::unique_lock lock(m_mutex);
                m_cv.wait(lock, [&] { return !m_queue.empty(); });

                // get a task.
                auto task = m_queue.front();
                m_queue.pop();
                lock.unlock();

                // do the task.
                task->run(m_context);
            }
        }));
    }

    void enqueue(TaskPtr& task) {
        std::lock_guard lock(m_mutex);
        m_queue.push(task);
        m_cv.notify_one();
    }

    void join() {
        m_thread->join();
    }

private:
    Context m_context;
    bool m_running{false};
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::unique_ptr<std::thread> m_thread;
    std::queue<TaskPtr> m_queue;
};
using ThreadPtr = Thread::Ptr;

// Simple thread pool.
class ThreadPool {
public:
    explicit ThreadPool(std::size_t size = 4)
        : m_size(size) {
        std::lock_guard lock(m_mutex);
        m_threads.reserve(size);
        for (auto n = 0; n < size; ++n) {
            printf("Spawning thread %d\n", n);
            m_threads.emplace_back(std::make_unique<Thread>(n));
        }
    }

    template <typename F, typename = std::enable_if_t<!std::is_same_v<F, TaskPtr>>>
    void submit(F&& f) {
        auto task = std::make_shared<Task>(std::forward<F>(f));
        submit(task);
    }

    void submit(TaskPtr& task) {
        std::lock_guard lock(m_mutex);
        m_current = (++m_current) % m_size;
        m_threads[m_current]->enqueue(task);
    }

    void join() {
        for (auto& thread : m_threads) {
            thread->join();
        }
    }

private:
    std::size_t m_current{};
    std::size_t m_size{};
    std::mutex m_mutex;
    std::vector<ThreadPtr> m_threads;
};

int main(int argc, char* argv[]) {
    ThreadPool pool{8};
    for (auto i = 0; i < 10; ++i) {
        printf("Addning a new task #%d\n", i);
        pool.submit([i](auto& ctx) { printf("Running task #%d on thread%d \n", i, ctx.id); });
    }
    pool.join();
    return 0;
}
