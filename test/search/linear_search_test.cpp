#include "test_helpers/search.h"

#include <algorithms/search/linear_search.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::search;
using namespace wingmann::utility::test_helpers;

TEST(linear_search, empty) {
    EXPECT_EQ(std::nullopt, linear_search(std::vector<int>{}, 1));
}

TEST(linear_search, one_value) {
    EXPECT_EQ(0, linear_search(std::vector<int>{64}, 64).value());
}

TEST(linear_search, several_values) {
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

TEST(linear_search, not_found) {
    std::vector<int> data;
    auto target = 1'001;

    for (std::size_t i = 0; i < 10; i++) {
        data = get_sorted_vector_with_random_values<int>();
        EXPECT_EQ(std::nullopt, linear_search(data, target));
    }
}
