#include "thread_pool.h"

#include <iostream>
#include <thread>
#include <vector>

#include "fmt/core.h"

namespace core {

ThreadPool::ThreadPool(size_t threads) {
    if (threads < 1) {
        throw std::invalid_argument("threads max size must be > 0");
    }
    num_threads = threads;
}

void ThreadPool::Start() {
    size_t num = 0;
    while (num < num_threads) {
        auto task = [this] {
            while (true) {
                auto job = this->task_queue.Recv();
                if (job.has_value()) {
                    job.value()();
                } else {
                    break;
                }
            }
        };
        workers.emplace_back(std::thread(task));
        num++;
    }
}

// ThreadPool* ThreadPool::Current() {}

void ThreadPool::Submit(Task task) { task_queue.Send(task); }

ThreadPool::~ThreadPool() {
    task_queue.Close();

    for (auto& worker : workers) {
        if (worker.joinable()) worker.join();
    }
}

}  // namespace core
