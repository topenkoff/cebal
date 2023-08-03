#include "thread_pool.h"

#include <iostream>
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
                auto job = this->task_queue.recv();
                if (job.has_value()) {
                    job.value()();
                } else {
                    break;
                }
            }
        };
        workers.push_back(std::thread(task));
        num++;
    }
}

// ThreadPool* ThreadPool::Current() {}

void ThreadPool::Submit(Task task) { task_queue.send(task); }

void ThreadPool::Stop() {
    task_queue.close();
    for (auto worker = workers.begin(); worker != workers.end(); worker++) {
        if (worker->joinable())
            worker->join();
    }
}

ThreadPool::~ThreadPool() {}

// ThreadPool::~ThreadPool() {
//     task_queue.close();
//     for (auto worker = workers.begin(); worker != workers.end(); worker++) {
//         worker->join();
//     }
// }

}  // namespace core
