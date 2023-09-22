#include "test_helpers/search.h"

#include <algorithms/search/jump_search.h>
#include <gtest/gtest.h>

TEST(algorithms_search, jump_search_empty) {
    EXPECT_EQ(std::nullopt, wingmann::algorithms::search::jump_search(std::vector<int>{}, 1));
}

TEST(algorithms_search, jump_search_one_value) {
    EXPECT_EQ(0, wingmann::algorithms::search::jump_search(std::vector<int>{64}, 64).value());
}

TEST(algorithms_search, jump_search_several_values) {
    std::vector<int> data;
    int target;
    int searched_target;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = wingmann::utility::test_helpers::get_sorted_vector_with_random_values<int>();
        target = wingmann::utility::test_helpers::get_value<int>(data);
        searched_target = data[wingmann::algorithms::search::jump_search(data, target).value()];

        EXPECT_EQ(target, searched_target);
    }
}

TEST(algorithms_search, jump_search_not_found) {
    std::vector<int> data;
    auto target = 1001;

    for (std::size_t test_count = 0; test_count < 10; ++test_count) {
        data = wingmann::utility::test_helpers::get_sorted_vector_with_random_values<int>();
        EXPECT_EQ(std::nullopt, wingmann::algorithms::search::jump_search(data, target));
    }
}
