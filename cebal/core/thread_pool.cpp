#include "thread_pool.h"

#include <iostream>
#include <vector>

namespace core {

ThreadPool::ThreadPool(size_t threads) {
    if (threads < 1) {
        throw std::invalid_argument("threads max size must be > 0");
    }
    size_t i = 0;
    while (i < threads) {
        auto queue = &task_queue;
        auto task = [queue, i]() {
            while (true) {
                std::cout << "worker " << i << " get job ";  // << std::end;
                auto job = queue->recv();
                if (job.has_value()) {
                    job.value()();
                } else {
                    break;
                }
            }
        };
        workers.push_back(std::thread(task));
        i++;
    };
};

ThreadPool::~ThreadPool() {
    for (auto worker = workers.begin(); worker != workers.end(); worker++) {
        worker->join();
    }
}

void ThreadPool::execute(Task task) { task_queue.send(task); }

}  // namespace core
