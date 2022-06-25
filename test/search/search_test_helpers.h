#ifndef WINGMANN_ALGORITHMS_TEST_SEARCH_SEARCH_TEST_HELPERS_H
#define WINGMANN_ALGORITHMS_TEST_SEARCH_SEARCH_TEST_HELPERS_H

#include "../test_helpers.h"

template<typename T>
requires std::integral<T>
auto get_value(const std::vector<T>& data)
{
    auto index = get_random_value<T>(0, data.size() - 1);
    auto value = data[index];

    return value;
}

#endif // WINGMANN_ALGORITHMS_TEST_SEARCH_SEARCH_TEST_HELPERS_H
