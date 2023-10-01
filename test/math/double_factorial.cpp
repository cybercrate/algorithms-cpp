#include <algorithms/math/double_factorial.h>
#include <gtest/gtest.h>

TEST(algorithms_math, double_factorial_1) {
    EXPECT_EQ(wingmann::algorithms::math::double_factorial(5), 15);
}

TEST(algorithms_math, double_factorial_2) {
    EXPECT_EQ(wingmann::algorithms::math::double_factorial(-8), 1);
}
