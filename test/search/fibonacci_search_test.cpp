#include "search.h"

#include "gtest/gtest.h"

#include <algorithm>

namespace search = wingmann::algorithms::search;

TEST(search, fibonacci_search_correct)
{
    std::vector data{1, 31, 231, 12, 2, 5, 51, 21, 23, 12, 3};
    std::sort(data.begin(), data.end());

    auto expected{8};
    auto actual = search::fibonacci_search(data, 31);

    EXPECT_EQ(expected, actual);
}

TEST(search, fibonacci_search_not_found)
{
    std::vector data{1, 31, 231, 12, 2, 5, 51, 21, 23, 12, 3};
    std::sort(data.begin(), data.end());

    auto actual = search::fibonacci_search(data, 4);

    EXPECT_EQ(static_cast<std::size_t>(-1), actual);
}

TEST(search, fibonacci_search_empty)
{
    std::vector<int> data{};
    std::sort(data.begin(), data.end());

    auto actual = search::fibonacci_search(data, 1);

    EXPECT_EQ(static_cast<std::size_t>(-1), actual);
}
