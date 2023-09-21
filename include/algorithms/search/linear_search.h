/// @file   linear_search.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Linear search algorithm implementation.
/// @date   2022-10-02
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H

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
/// @see https://en.wikipedia.org/wiki/Linear_search
///
template<std::totally_ordered T>
std::optional<std::size_t> linear_search(const std::vector<T>& data, const T& value) {
    if (data.empty()) {
        return std::nullopt;
    }
    for (std::size_t i = 0; i < data.size(); ++i) {
        if (data[i] == value) {
            return i;
        }
    }
    return std::nullopt;
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H
