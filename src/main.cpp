#include <core/Clock.hpp>
#include <core/Random.hpp>
#include <book/Order.hpp>
#include <book/OrderId.hpp>
#include <iostream>

int main() {
    core::Clock clock;
    clock.advance(1'000'000);
    std::cout << "Time = " << clock.now() << " ns" << std::endl;

    core::Random rng(123);
    std::cout << "Uniform = " << rng.uniform() << std::endl;

    uint64_t id1 = book::OrderId::next();
    book::Order o(id1, core::Side::Buy, 100, 4, 0);

    std::cout << o.str() << std::endl;
}
