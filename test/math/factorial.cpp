#include <algorithms/math/factorial.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::math;

TEST(algorithms_math, factorial_1)
{
    EXPECT_EQ(factorial(5), 120);
}

TEST(algorithms_math, factorial_2)
{
    EXPECT_EQ(factorial(-8), 1);
}
