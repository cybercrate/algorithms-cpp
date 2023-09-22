#include "test_helpers/general.h"

#include <algorithms/sorting/bubble_sort.h>
#include <gtest/gtest.h>

TEST(algorithms_sorting, bubble_sort_empty) {
    std::vector<int> data{};
    EXPECT_FALSE(wingmann::algorithms::sorting::bubble_sort(data));
}

TEST(algorithms_sorting, bubble_sort_one_value) {
    std::vector data{64};
    EXPECT_FALSE(wingmann::algorithms::sorting::bubble_sort(data));
}

TEST(algorithms_sorting, bubble_sort_two_values) {
    std::vector<int> data;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = wingmann::utility::test_helpers::get_vector_with_random_values<int>(2);

        auto sorted = wingmann::algorithms::sorting::bubble_sort(data);
        EXPECT_TRUE(sorted);

        for (std::size_t i = 0; i < data.size() - 1; ++i) {
            EXPECT_TRUE(data[i] <= data[i + 1]);
        }
    }
}

TEST(algorithms_sorting, bubble_sort_several_values_ascending) {
    std::vector<int> data;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = wingmann::utility::test_helpers::get_vector_with_random_values<int>(1000);

        auto sorted = wingmann::algorithms::sorting::bubble_sort(data);
        EXPECT_TRUE(sorted);

        for (std::size_t i = 0; i < data.size() - 1; ++i) {
            EXPECT_TRUE(data[i] <= data[i + 1]);
        }
    }
}

TEST(algorithms_sorting, bubble_sort_several_values_descending) {
    std::vector<int> data;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = wingmann::utility::test_helpers::get_vector_with_random_values<int>(1000);

        auto sorted = bubble_sort(data, wingmann::algorithms::sorting::sorting_type::descending);
        EXPECT_TRUE(sorted);

        for (std::size_t i = 0; i < data.size() - 1; ++i) {
            EXPECT_TRUE(data[i] >= data[i + 1]);
        }
    }
}
