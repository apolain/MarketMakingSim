#include <catch2/catch_all.hpp>
#include <book/OrderId.hpp>

TEST_CASE("Order id", "[OrderId]") {
	uint64_t id1 = book::OrderId::next();
	uint64_t id2 = book::OrderId::next();
	uint64_t id3 = book::OrderId::next();

	REQUIRE(id1 == 1);
	REQUIRE(id2 > id1);
	REQUIRE(id3 > id2);
	REQUIRE(id3 - id1 == 2);
}