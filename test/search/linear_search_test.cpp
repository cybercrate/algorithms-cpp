#include "gtest/gtest.h"

#include "search.h"

TEST(algorithms_search, linear_search_1)
{
    // Arrange.
    std::vector data{1, 3, 5, 7, 9, 8, 6, 4, 2};

    // Act.
    std::sort(data.begin(), data.end());

    auto expected{3};
    auto actual = wing::search::binary_search(data, 4);

    // Assert.
    EXPECT_EQ(expected, actual);
}

TEST(algorithms_search, linear_search_2)
{
    // Arrange.
    std::vector<int> data{};

    // Act.
    std::sort(data.begin(), data.end());

    auto expected = static_cast<std::size_t>(-1);
    auto actual = wing::search::binary_search(data, 1);

    // Assert.
    EXPECT_EQ(expected, actual);
}
