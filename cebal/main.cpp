#include <iostream>

#include "core/thread_pool.h"

int main() {
    auto tp = core::ThreadPool(5);

    for (int i; i < 50; i++) {
        tp.execute([i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(i * 10));
            std::cout << "# " << i << std::endl;
        });
    }

    return 0;
}
