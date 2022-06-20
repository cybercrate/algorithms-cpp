#include "search.h"

#include "gtest/gtest.h"

using namespace wingmann::algorithms::search;

TEST(jump_search, empty)
{
    EXPECT_EQ(std::nullopt, jump_search(std::vector<int>{}, 1));
}

TEST(jump_search, one_value)
{
    EXPECT_EQ(0, jump_search(std::vector<int>{64}, 64).value());
}

TEST(jump_search, several_values)
{
    auto data = std::vector{1, 1, 3, 7, 9, 11, 12, 14, 21, 34, 35, 64, 87, 91, 128, 199, 201};
    auto target{34};

    EXPECT_EQ(9, jump_search(data, target));
}

TEST(jump_search, not_found)
{
    auto data = std::vector{1, 1, 3, 7, 9, 11, 12, 14, 21, 34, 35, 64, 87, 91, 128, 199, 201};
    auto target{2};

    EXPECT_EQ(std::nullopt, jump_search(data, target));
}
