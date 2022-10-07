#include <algorithms/math/fibonacci.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::math;

TEST(algorithms_math, fibonacci_1)
{
    EXPECT_EQ(fibonacci(12), 144);
}

TEST(algorithms_math, fibonacci_2)
{
    EXPECT_EQ(fibonacci(13), 233);
}
