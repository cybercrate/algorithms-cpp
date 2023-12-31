/// @file   ternary_search.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Ternary search algorithm implementation.
/// @date   2022-10-02
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_SEARCH_TERNARY_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_TERNARY_SEARCH_H

#include "binary_search.h"

#include <concepts>
#include <optional>
#include <utility>
#include <vector>

namespace wingmann::algorithms::search {

/// @brief Finds value in vector.
///
/// @tparam T    Generic type of vector.
/// @param data  Vector to be searched in.
/// @param value Value to be searched.
/// @return      Index of the found item or std::nullopt if not found.
///
/// @see https://en.wikipedia.org/wiki/Ternary_search
///
template<std::totally_ordered T>
std::optional<std::size_t> ternary_search(const std::vector<T>& data, const T& target) {
    if (data.empty()) {
        return std::nullopt;
    } else if (data.size() < 1'000) {
        return binary_search(data, target);
    }
    std::pair<std::size_t, std::size_t> index{{}, data.size()};
    std::pair<std::size_t, std::size_t> middle_index{};
    std::pair<std::size_t, std::size_t> value{};

    while (index.first < index.second) {
        auto temp = (index.second - index.first) / 3;

        middle_index.first = index.first + temp;
        middle_index.second = index.second - temp;

        value.first = data[middle_index.first];
        value.second = data[middle_index.second];

        if (target == static_cast<T>(value.first)) {
            return middle_index.first;
        }
        if (target == static_cast<T>(value.second)) {
            return middle_index.second;
        }
        if (target < static_cast<T>(value.first)) {
            index.second = middle_index.first - 1;
        } else if (target > static_cast<T>(value.second)) {
            index.first = middle_index.second + 1;
        } else {
            index.first = middle_index.first + 1;
            index.second = middle_index.second - 1;
        }
    }
    return std::nullopt;
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_TERNARY_SEARCH_H
