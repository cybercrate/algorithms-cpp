#include <algorithms/math/factorial.h>
#include <gtest/gtest.h>

TEST(algorithms_math, factorial_loop_1) {
    EXPECT_EQ(wingmann::algorithms::math::factorial(5), 120);
}

TEST(algorithms_math, factorial_loop_2) {
    EXPECT_EQ(wingmann::algorithms::math::factorial(-8), 1);
}