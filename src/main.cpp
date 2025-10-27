#include <iostream>
#include "Test.hpp"
#include <fmt/core.h>

int main() {
    Test t;
    std::cout << t.greet("world") << '\n';
    return 0;
}
