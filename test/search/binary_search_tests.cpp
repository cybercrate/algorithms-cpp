#include "gtest/gtest.h"

#include "binary_search.h"

TEST(Algorithms_Search, BinarySearch_1)
{
    // Arrange.
    std::vector data{1, 3, 5, 7, 9, 8, 6, 4, 2};

    // Act.
    std::sort(data.begin(), data.end());

    std::size_t expected{3};
    std::size_t actual = binary_search(data, 4);

    // Assert.
    ASSERT_EQ(expected, actual);
}
