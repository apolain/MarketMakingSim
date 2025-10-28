#pragma once
#include <atomic>

namespace book {
    struct OrderId {
        static uint64_t next() {
            static std::atomic<uint64_t> ctr{ 1 };
            return ctr.fetch_add(1, std::memory_order_relaxed);
        }
    };
}
