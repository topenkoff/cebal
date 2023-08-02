#pragma once

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <thread>
#include <vector>

#include "queue.h"

namespace core {

using Task = std::function<void()>;

class ThreadPool {
   public:
    explicit ThreadPool(size_t threads);

    // Non-copyable
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    // Non-movable
    ThreadPool(ThreadPool&&) = delete;
    ThreadPool& operator=(ThreadPool&&) = delete;

    ~ThreadPool();
    void execute(Task task);

   private:
    Queue<Task> task_queue;
    std::vector<std::thread> workers;
};

}  // namespace core

#endif
