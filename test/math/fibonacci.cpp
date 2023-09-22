#include <algorithms/math/fibonacci.h>
#include <gtest/gtest.h>

TEST(algorithms_math, fibonacci_1) {
    EXPECT_EQ(wingmann::algorithms::math::fibonacci(12), 144);
}

TEST(algorithms_math, fibonacci_2) {
    EXPECT_EQ(wingmann::algorithms::math::fibonacci(13), 233);
}
