#include "test_helpers/general.h"

#include <algorithms/sorting/bubble_sort.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::sorting;
using namespace wingmann::utility::test_helpers;

TEST(bubble_sort, empty)
{
    std::vector<int> data{};
    EXPECT_FALSE(bubble_sort(data));
}

TEST(bubble_sort, one_value)
{
    std::vector<int> data{64};
    EXPECT_FALSE(bubble_sort(data));
}

TEST(bubble_sort, two_values)
{
    std::vector<int> data;

    for (std::size_t i = 0; i < 10; i++) {
        data = get_vector_with_random_values<int>(2);
        bubble_sort(data);

        for (std::size_t j = 0; j < data.size() - 1; ++j)
            EXPECT_TRUE(data[j] <= data[j + 1]);
    }
}

TEST(bubble_sort, several_values)
{
    std::vector<int> data;

    for (std::size_t i = 0; i < 10; i++) {
        data = get_vector_with_random_values<int>(1'000);
        bubble_sort(data);

        for (std::size_t j = 0; j < data.size() - 1; ++j)
            EXPECT_TRUE(data[j] <= data[j + 1]);
    }
}
