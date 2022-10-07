#include <algorithms/math/square_root.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::math;

TEST(algorithms_math, square_root_1)
{
    EXPECT_EQ(square_root(64), 8);
}

TEST(algorithms_math, square_root_2)
{
    EXPECT_EQ(square_root(64.0f), 8.0f);
}

TEST(algorithms_math, square_root_3)
{
    EXPECT_EQ(square_root(64.0), 8.0);
}
