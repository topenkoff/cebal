#pragma once

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

namespace core {

class ThreadPool {
   public:
    ThreadPool(int threads);
    ~ThreadPool();
    void execute();
};

}  // namespace core

#endif
