#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include <mutex>
#include <optional>
#include <queue>

namespace core {

template <typename T>
class Queue {
   public:
    Queue() = default;
    ~Queue() = default;
    Queue& operator=(Queue other) { return *this; }
    bool send(T value) {
        q.push(value);
        return true;
    }
    std::optional<T> recv() {
        std::lock_guard<std::mutex> lock(q_mutex);

        if (q.empty()) {
            return std::nullopt;
        } else {
            auto value = std::move(q.front());
            q.pop();
            return value;
        }
    }

   private:
    std::queue<T> q;
    std::mutex q_mutex;
};

};  // namespace core
#endif
