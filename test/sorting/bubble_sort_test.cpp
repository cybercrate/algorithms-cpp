#include "gtest/gtest.h"

#include "sorting.h"

namespace sorting = wingmann::algorithms::sorting;

TEST(sorting, bubble_sort)
{
    std::vector<int> data{7, 9, 1, 22, 2, 1, 76, 128};
    sorting::bubble_sort(data);

    for (int i = 0; i < data.size() - 1; ++i)
        EXPECT_TRUE(data[i] <= data[i + 1]);
}
