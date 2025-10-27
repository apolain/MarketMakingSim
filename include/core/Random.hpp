#pragma once
#include <random>

namespace core {

    class Random {
    public:
        explicit Random(uint64_t seed = 42) : gen_(seed) {}

        double uniform(double a = 0.0, double b = 1.0) {
            std::uniform_real_distribution<double> dist(a, b);
            return dist(gen_);
        }

        double normal(double mean = 0.0, double std = 1.0) {
            std::normal_distribution<double> dist(mean, std);
            return dist(gen_);
        }

        int poisson(double lambda) {
            std::poisson_distribution<int> dist(lambda);
            return dist(gen_);
        }

        std::mt19937_64& engine() { return gen_; }

    private:
        std::mt19937_64 gen_;
    };

}
