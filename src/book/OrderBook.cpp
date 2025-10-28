#include <book/OrderBook.hpp>
#include <optional>

namespace book {
    std::optional<core::Price> OrderBook::best_bid() const {
        if (bids_.empty()) return std::nullopt;
        return bids_.begin()->first;
    }
    std::optional<core::Price> OrderBook::best_ask() const {
        if (asks_.empty()) return std::nullopt;
        return asks_.begin()->first;
    }
}



