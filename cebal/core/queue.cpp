#include "queue.h"

#include <optional>
#include <queue>

namespace core {

template <typename T>
Queue<T>::Queue() {
    q = std::queue<T>();
}

template <typename T>
Queue<T>::~Queue() {
    delete q;
};

template <typename T>
bool Queue<T>::send(T value) {
    q.push(value);
    return true;
}

template <typename T>
std::optional<T> Queue<T>::recv() {
    return q.front();
}

}  // namespace core
