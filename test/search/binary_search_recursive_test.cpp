#include "test_helpers/search.h"

#include <algorithms/search/binary_search_recursive.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::search;
using namespace wingmann::utility::test_helpers;

TEST(binary_search_recursive, empty) {
    EXPECT_EQ(std::nullopt, binary_search_recursive(std::vector<int>{}, 1));
}

TEST(binary_search_recursive, one_value) {
    EXPECT_EQ(0, binary_search_recursive(std::vector<int>{64}, 64).value());
}

TEST(binary_search_recursive, several_values) {
    std::vector<int> data;
    int target;
    int searched_target;

    for (std::size_t i = 0; i < 10; i++) {
        data = get_sorted_vector_with_random_values<int>();
        target = get_value<int>(data);
        searched_target = data[binary_search_recursive(data, target).value()];

        EXPECT_EQ(target, searched_target);
    }
}

TEST(binary_search_recursive, not_found) {
    std::vector<int> data;
    auto target = 1'001;

    for (std::size_t i = 0; i < 10; i++) {
        data = get_sorted_vector_with_random_values<int>();
        EXPECT_EQ(std::nullopt, binary_search_recursive(data, target));
    }
}
