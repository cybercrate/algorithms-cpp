#include <algorithms/math/double_factorial.h>
#include <gtest/gtest.h>

TEST(algorithms_math, double_factorial_loop_1) {
    EXPECT_EQ(wingmann::algorithms::math::double_factorial_loop(5), 15);
}

TEST(algorithms_math, double_factorial_loop_2) {
    EXPECT_EQ(wingmann::algorithms::math::double_factorial_loop(-8), 1);
}
