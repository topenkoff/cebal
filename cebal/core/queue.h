#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <optional>
#include <queue>

namespace core {

template <typename T>
class Queue {
   public:
    Queue();
    ~Queue();
    bool send(T value);
    std::optional<T> recv();

   private:
    std::queue<T> q;
};

};  // namespace core
#endif
