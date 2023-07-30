#include "thread_pool.h"

#include <vector>

#include "queue.h"

namespace core {

ThreadPool::ThreadPool(int threads) {
    task_queue = Queue<Task>();
    workers = std::vector<Worker>(threads);
}

void ThreadPool::execute(Task task) { task_queue.send(task); }

void ThreadPool::start() {
    while (true) {
        auto task = task_queue.recv();
        if (task.has_value())
            task.value()();
        else {
            break;
        }
    }
};

}  // namespace core
