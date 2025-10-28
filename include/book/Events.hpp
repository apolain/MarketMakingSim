#pragma once
#include <core/Types.hpp>
#include <book/Order.hpp>
#include <vector>

namespace book {
	struct Trade {
		Order::Id maker_id;
		Order::Id taker_id;
		core::Side taker_side;
		core::Price price;
		core::Quantity quantity;
		core::TimeNs ts;
	};
	struct AddResult {
		std::vector<Trade> trades;
		bool resting = false;
	};
}