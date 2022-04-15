#include "gtest/gtest.h"

#include "search.h"

TEST(algorithms_search, linear_search_1)
{
    std::vector data{1, 3, 5, 7, 9, 8, 6, 4, 2};
    std::sort(data.begin(), data.end());

    auto actual = wing::algo::binary_search(data, 4);

    EXPECT_EQ(3, actual);
}

TEST(algorithms_search, linear_search_2)
{
    std::vector<int> data{};
    std::sort(data.begin(), data.end());

    auto expected = std::numeric_limits<std::size_t>::max();
    auto actual = wing::algo::binary_search(data, 1);

    EXPECT_EQ(expected, actual);
}
