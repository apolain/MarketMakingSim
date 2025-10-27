#pragma once
#include <cstdint>
#include <string>
#include <core/Types.hpp>

namespace book {

    class Order {
    public:
        using Id = uint64_t;

        Order(Id id,
            core::Side side,
            core::Price price,
            core::Quantity qty,
            core::TimeNs timestamp)
            : id_(id), side_(side), price_(price), quantity_(qty), timestamp_(timestamp) {
        }

        // --- Getters ---
        Id id() const { return id_; }
        core::Side side() const { return side_; }
        core::Price price() const { return price_; }
        core::Quantity quantity() const { return quantity_; }
        core::TimeNs timestamp() const { return timestamp_; }

        // --- Setters / Updates ---
        void reduce(core::Quantity q) {
            quantity_ = (q >= quantity_) ? 0 : (quantity_ - q);
        }

        std::string str() const {
            char buf[64];
            std::snprintf(buf, sizeof(buf),
                "[Order id=%llu side=%s price=%.2f qty=%d]",
                static_cast<unsigned long long>(id_),
                core::side_to_str(side_),
                price_,
                quantity_);
            return std::string(buf);
        }

        bool is_filled() const { return quantity_ <= 0; }

    private:
        Id id_;
        core::Side side_;
        core::Price price_;
        core::Quantity quantity_;
        core::TimeNs timestamp_;
    };

} 
