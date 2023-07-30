#pragma once

#include <vector>

#include "queue.h"
#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <functional>

#include "queue.h"

namespace core {

class Worker {};

using Task = std::function<void()>;

class ThreadPool {
   public:
    ThreadPool(int threads);
    void execute(Task task);
    void start();

   private:
    Queue<Task> task_queue;
    std::vector<Worker> workers;
};

}  // namespace core

#endif
