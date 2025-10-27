#pragma once
#include <chrono>
#include <cstdint>

namespace core {
    using TimePoint = uint64_t;

    class Clock {
    public:
        Clock() : now_ns_(0) {}

        void advance(uint64_t dt_ns) { now_ns_ += dt_ns; }
        uint64_t now() const { return now_ns_; }

    private:
        uint64_t now_ns_;
    };

}
