#ifndef WINGMANN_TEST_HELPERS_SEARCH_H
#define WINGMANN_TEST_HELPERS_SEARCH_H

#include "general.h"

namespace wingmann::utility::test_helpers {

template<typename T>
requires std::integral<T>
auto get_value(const std::vector<T>& data) {
    auto index = get_random_value<T>(0, data.size() - 1);
    auto value = data[index];

    return value;
}

} // namespace wingmann::utility::test_helpers

#endif // WINGMANN_TEST_HELPERS_SEARCH_H
