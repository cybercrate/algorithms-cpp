#include <algorithms/math/fibonacci.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::math;

TEST(algorithms_math, fibonacci_loop_1)
{
    EXPECT_EQ(fibonacci_loop(12), 144);
}

TEST(algorithms_math, fibonacci_loop_2)
{
    EXPECT_EQ(fibonacci_loop(13), 233);
}
