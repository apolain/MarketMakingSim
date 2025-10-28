#include <catch2/catch_all.hpp>
#include <book/Order.hpp>
#include <core/Types.hpp>

TEST_CASE("Order basic construction", "[Order]") {
    using namespace core;
    using namespace book;

    // --- GIVEN ---
    const Order::Id id = 42;
    const Side side = Side::Buy;
    const Price price = 100.25;
    const Quantity qty = 10;
    const TimeNs ts = 123456789ULL;

    // --- WHEN ---
    book::Order o(id, side, price, qty, ts);

    // --- THEN ---
    REQUIRE(o.id() == id);
    REQUIRE(o.side() == side);
    REQUIRE(o.price() == Catch::Approx(price));
    REQUIRE(o.quantity() == qty);
    REQUIRE(o.timestamp() == ts);
    REQUIRE_FALSE(o.is_filled());
}

TEST_CASE("Order reduction and filled status", "[Order]") {
    using namespace core;
    book::Order o(1, Side::Sell, 99.50, 5, 0);

    SECTION("Partial reduction") {
        o.reduce(2);
        REQUIRE(o.quantity() == 3);
        REQUIRE_FALSE(o.is_filled());
    }

    SECTION("Complete reduction") {
        o.reduce(10);  // dépasse la quantité
        REQUIRE(o.quantity() == 0);
        REQUIRE(o.is_filled());
    }
}

TEST_CASE("Order string representation", "[Order]") {
    using namespace core;
    book::Order buy_order(1, Side::Buy, 100.0, 4, 0);
    book::Order sell_order(2, Side::Sell, 101.0, 7, 0);

    auto s1 = buy_order.str();
    auto s2 = sell_order.str();

    INFO("Buy order string: " << s1);
    INFO("Sell order string: " << s2);

    REQUIRE(s1.find("BUY") != std::string::npos);
    REQUIRE(s2.find("SELL") != std::string::npos);

    REQUIRE(s1.find("100") != std::string::npos);
    REQUIRE(s2.find("101") != std::string::npos);
}