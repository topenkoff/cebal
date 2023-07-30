#include <iostream>

#include "core/queue.h"

using namespace core;

int main() {
    auto q = Queue<int>();
    q.send(42);
    q.send(43);
    q.send(44);
    std::cout << q.recv().value() << std::endl;
    std::cout << q.recv().value() << std::endl;
    std::cout << q.recv().value() << std::endl;
    return 0;
}
