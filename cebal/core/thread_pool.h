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
    ~ThreadPool();

    // Non-copyable
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    // Non-movable
    ThreadPool(ThreadPool&&) = delete;
    ThreadPool& operator=(ThreadPool&&) = delete;

    void Start();

    void Submit(Task);

    // Locates current thread pool from worker thread
    // static ThreadPool* Current();

    // Waits until outstanding work count reaches zero
    // void WaitIdle();

    void Stop();

    int Size() { return task_queue.Size(); }

   private:
    size_t num_threads;
    Queue<Task> task_queue;
    std::vector<std::thread> workers;
};

}  // namespace core

#endif
