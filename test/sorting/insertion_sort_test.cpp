#include "test_helpers/general.h"

#include <algorithms/sorting/insertion_sort.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::sorting;
using namespace wingmann::utility::test_helpers;

TEST(algorithms_sorting, insertion_sort_empty)
{
    std::vector<int> data{};
    EXPECT_FALSE(insertion_sort(data));
}

TEST(algorithms_sorting, insertion_sort_one_value)
{
    std::vector data{64};
    EXPECT_FALSE(insertion_sort(data));
}

TEST(algorithms_sorting, insertion_sort_two_values)
{
    std::vector<int> data;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = get_vector_with_random_values<int>(2);

        auto sorted = insertion_sort(data);
        EXPECT_TRUE(sorted);

        for (std::size_t i = 0; i < data.size() - 1; ++i)
            EXPECT_TRUE(data[i] <= data[i + 1]);
    }
}

TEST(algorithms_sorting, insertion_sort_several_values_ascending)
{
    std::vector<int> data;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = get_vector_with_random_values<int>(1000);

        auto sorted = insertion_sort(data);
        EXPECT_TRUE(sorted);

        for (std::size_t i = 0; i < data.size() - 1; ++i)
            EXPECT_TRUE(data[i] <= data[i + 1]);
    }
}

TEST(algorithms_sorting, insertion_sort_several_values_descending)
{
    std::vector<int> data;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = get_vector_with_random_values<int>(1000);

        auto sorted = insertion_sort(data, sorting_type::descending);
        EXPECT_TRUE(sorted);

        for (std::size_t i = 0; i < data.size() - 1; ++i)
            EXPECT_TRUE(data[i] >= data[i + 1]);
    }
}
