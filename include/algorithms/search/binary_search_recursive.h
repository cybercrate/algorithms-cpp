/// @file   binary_search_recursive.h
/// @brief  Binary search recursive algorithm implementation.
/// @author Alexander Shavrov

#ifndef WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_RECURSIVE_H
#define WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_RECURSIVE_H

#include <optional>
#include <vector>
#include <concepts>

namespace wingmann::algorithms::search {

/// @brief Finds value in vector.
///
/// @tparam T          Generic type of vector.
/// @param data        Vector to be searched in.
/// @param target      Value to be searched.
/// @param left_index  Begin index.
/// @param right_index End index.
/// @return            Index of the found item or std::nullopt if not found.
///
/// @see https://en.wikipedia.org/wiki/Binary_search_algorithm
///
template<std::totally_ordered T>
std::optional<std::size_t> binary_search_recursive(
    const std::vector<T>& data,
    const T& target,
    std::size_t left_index,
    std::size_t right_index)
{
    if (left_index < right_index) {
        std::size_t middle_index = left_index + (right_index - left_index) / 2;

        if (target == data[middle_index])
            return middle_index;

        if (target <= data[middle_index])
            return binary_search_recursive(data, target, left_index, middle_index - 1);

        return binary_search_recursive(data, target, middle_index + 1, right_index);
    }
    return std::nullopt;
}

/// @brief Finds value in vector.
///
/// @tparam T     Generic type of vector.
/// @param data   Vector to be searched in.
/// @param target Value to be searched.
/// @return       Index of the found item or std::nullopt if not found.
///
/// @see https://en.wikipedia.org/wiki/Binary_search_algorithm
///
template<std::totally_ordered T>
std::optional<std::size_t> binary_search_recursive(const std::vector<T>& data, const T& target)
{
    if (data.empty())
        return std::nullopt;
    else if (data.size() == 1 && target == data[0])
        return 0;
    else
        return binary_search_recursive(data, target, 0, data.size() - 1);
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_RECURSIVE_H
