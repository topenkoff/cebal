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
    void Send(T value);
    std::optional<T> Recv();
    void Close();
    int Size();

   private:
    bool closed = false;
    std::deque<T> data;
    std::shared_mutex m;
    std::condition_variable_any cv;
};

template <typename T>
void Queue<T>::Send(T value) {
    std::unique_lock<std::shared_mutex> guard(m);
    data.push_back(value);
    cv.notify_one();
}

template <typename T>
std::optional<T> Queue<T>::Recv() {
    while (true) {
        std::unique_lock<std::shared_mutex> guard(m);
        if (!data.empty()) {
            auto value = data.front();
            data.pop_front();
            return value;
        } else if (data.empty() && !closed) {
            cv.wait(guard);
        } else {
            return std::nullopt;
        }
    }
}

template <typename T>
void Queue<T>::Close() {
    std::unique_lock<std::shared_mutex> guard(m);
    closed = true;
    cv.notify_all();
}

template <typename T>
int Queue<T>::Size() {
    return data.size();
}

};  // namespace core
#endif
