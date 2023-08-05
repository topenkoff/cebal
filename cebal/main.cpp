#include <iostream>

#include "core/thread_pool.h"
#include "fmt/core.h"

int main() {
    auto pool = core::ThreadPool{2};
    for (int i = 0; i < 10; i++) {
        // clang-format off
        pool.Submit([i]() {
            fmt::println("# {}", i);
        });
    }
    fmt::println("Task queue size {}", pool.Size());
    pool.Start();
    for (int i=10; i < 20; i++) {
        // clang-format off
        pool.Submit([i]() {
            fmt::println("# {}", i);
        });
    }
    return 0;
}
