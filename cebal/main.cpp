#include <iostream>

#include "core/queue.h"
#include "core/thread_pool.h"

using namespace core;

int main() {
    auto tp = ThreadPool(5);
    for (int i; i < 10; i++) {
        tp.execute([i]() {
            std::cout << "# ";
            std::cout << i << std::endl;
        });
    }
    tp.start();
    return 0;
}
