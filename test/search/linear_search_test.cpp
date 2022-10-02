#include "test_helpers/search.h"

#include <algorithms/search/linear_search.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::search;
using namespace wingmann::utility::test_helpers;

TEST(algorithms_search, linear_search_empty)
{
    EXPECT_EQ(std::nullopt, linear_search(std::vector<int>{}, 1));
}

TEST(algorithms_search, linear_search_one_value)
{
    EXPECT_EQ(0, linear_search(std::vector<int>{64}, 64).value());
}

TEST(algorithms_search, linear_search_several_values)
{
    std::vector<int> data;
    int target;
    int searched_target;

    for (std::size_t i = 0; i < 10; i++) {
        data = get_sorted_vector_with_random_values<int>(100);
        target = get_value<int>(data);
        searched_target = data[linear_search(data, target).value()];

        EXPECT_EQ(target, searched_target);
    }
}

TEST(algorithms_search, linear_search_not_found)
{
    std::vector<int> data;
    auto target = 1'001;

    for (std::size_t i = 0; i < 10; i++) {
        data = get_sorted_vector_with_random_values<int>();
        EXPECT_EQ(std::nullopt, linear_search(data, target));
    }
}
