#include <algorithms/math/square_root.h>

#include <gtest/gtest.h>

#include <string>

using namespace wingmann::algorithms::math;

TEST(algorithms_math, square_root_1)
{
    auto x = square_root(262'144);
    auto y = static_cast<int>(std::sqrt(262'144));

    EXPECT_EQ(std::to_string(x), std::to_string(y));
}

TEST(algorithms_math, square_root_2)
{
    auto x = square_root(2'126'781.656f);
    auto y = std::sqrt(2'126'781.656f);

    EXPECT_EQ(std::to_string(x), std::to_string(y));
}

TEST(algorithms_math, square_root_3)
{
    auto x = square_root(35'611.289);
    auto y = std::sqrt(35'611.289);

    EXPECT_EQ(std::to_string(x), std::to_string(y));
}
