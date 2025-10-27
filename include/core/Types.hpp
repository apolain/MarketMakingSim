#pragma once
#include <cstdint>

namespace core {

    using Price = double;
    using Quantity = int;
    using TimeNs = uint64_t;
    
    enum class Side { Buy = 1, Sell = -1 };

    inline const char* side_to_str(Side s) {
        return (s == Side::Buy) ? "BUY" : "SELL";
    }

} // namespace core
