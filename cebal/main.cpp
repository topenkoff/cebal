#include <iostream>

#include "core/thread_pool.h"
#include "fmt/core.h"

int main() {
    auto pool = core::ThreadPool{ 10 };
    for (int i=0; i < 1000; i++) {
        pool.Submit([i]() {
            fmt::println("# {}", i);
        });
    }
    fmt::println("Task queue size {}", pool.Size());
    pool.Start();
    for (int i=0; i < 20; i++) {
        pool.Submit([i]() {
            fmt::println("# {}", i);
        });
    }
    fmt::println("Task queue size {}", pool.Size());
    pool.Stop();
    fmt::println("Task queue size {}", pool.Size());
    return 0;
}
