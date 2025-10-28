
#pragma once
#include <book/Order.hpp>
#include <core/Types.hpp>
#include <book/Events.hpp>
#include <optional>
#include <deque>
#include <map>

namespace book {
	class OrderBook {
	public:
		std::optional<core::Price> best_bid() const;
		std::optional<core::Price> best_ask() const;
		
		book::AddResult add_limit(Order&& taker);

		bool cancel(Order::Id id);

		void clear();

	private:
		using Level = std::deque<Order>;

		std::map<core::Price, Level, std::greater<>> bids_;
		std::map<core::Price, Level> asks_;

		book::AddResult match_buy(Order& taker);
		book::AddResult match_sell(Order& taker);
	};
}