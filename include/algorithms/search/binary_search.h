/// @file   binary_search.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Binary search algorithm implementation.
/// @date   2022-10-02
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H

#include <concepts>
#include <optional>
#include <vector>

namespace wingmann::algorithms::search {

/// @brief Finds value in vector.
///
/// @tparam T    Generic type of vector.
/// @param data  Vector to be searched in.
/// @param value Value to be searched.
/// @return      Index of the found item or std::nullopt if not found.
///
/// @see https://en.wikipedia.org/wiki/Binary_search_algorithm
///
template<std::totally_ordered T>
std::optional<std::size_t> binary_search(const std::vector<T>& data, const T& target) {
    if (data.empty()) {
        return std::nullopt;
    }
    std::size_t left_index{};
    std::size_t right_index = data.size();
    std::size_t middle_index;

    while (left_index < right_index) {
        middle_index = left_index + (right_index - left_index) / 2;

        if (auto& current_value = data[middle_index]; target == current_value) {
            return middle_index;
        } else if (target < current_value) {
            right_index = middle_index;
        } else {
            left_index = middle_index + 1;
        }
    }
    return std::nullopt;
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H
