#include <algorithms/math/fibonacci.h>
#include <gtest/gtest.h>

TEST(algorithms_math, fibonacci_loop_1) {
    EXPECT_EQ(wingmann::algorithms::math::fibonacci_loop(12), 144);
}

TEST(algorithms_math, fibonacci_loop_2) {
    EXPECT_EQ(wingmann::algorithms::math::fibonacci_loop(13), 233);
}
