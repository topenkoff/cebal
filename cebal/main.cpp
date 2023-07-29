#include <iostream>
#include "core/queue.h"

using namespace core;

int main() {
    auto q = Queue<int>();
    int val = 10;
    auto res = q.send(val);
    auto r = q.recv().value();
    std::cout << r << std::endl;
    return 0;
}
