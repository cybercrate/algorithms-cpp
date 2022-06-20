#include "gtest/gtest.h"

#include "sorting.h"

using namespace wingmann::algorithms::sorting;

TEST(bubble_sort, empty)
{
    auto data = std::vector<int>{};
    auto sorted = bubble_sort(data);

    EXPECT_FALSE(sorted);
}

TEST(bubble_sort, one_value)
{
    auto data = std::vector<int>{64};
    auto sorted = bubble_sort(data);

    EXPECT_FALSE(sorted);
}

TEST(bubble_sort, two_values)
{
    auto data = std::vector{512, 64};
    bubble_sort(data);

    for (int i = 0; i < data.size() - 1; ++i)
        EXPECT_TRUE(data[i] <= data[i + 1]);
}

TEST(bubble_sort, several_values)
{
    auto data = std::vector{12, 199, 3, 128, 9, 201, 1, 14, 21, 34, 91, 64, 87, 35, 7, 1, 11};
    bubble_sort(data);

    for (int i = 0; i < data.size() - 1; ++i)
        EXPECT_TRUE(data[i] <= data[i + 1]);
}
