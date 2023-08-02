#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <condition_variable>
#include <deque>
#include <optional>
#include <shared_mutex>

namespace core {

template <typename T>
class Queue {
   public:
    void send(T value) {
        std::unique_lock<std::shared_mutex> guard(m);
        data.push_back(value);
        guard.unlock();
        cv.notify_one();
    }

    std::optional<T> recv() {
        std::unique_lock<std::shared_mutex> guard(m);
        cv.wait(guard, [this] { return !data.empty(); });
        auto value = data.front();
        data.pop_front();
        return value;
    }

   private:
    std::deque<T> data;
    std::shared_mutex m;
    std::condition_variable_any cv;
};

};  // namespace core
#endif
