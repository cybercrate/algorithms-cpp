/// @file   merge_sort.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Merge sort algorithm implementation.
/// @date   2022-10-16
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_SORTING_MERGE_SORT_H
#define WINGMANN_ALGORITHMS_SORTING_MERGE_SORT_H

#include "sorting_type.h"

#include <concepts>
#include <vector>
#include <utility>

namespace wingmann::algorithms::sorting {

namespace {

// Sorts the vector using a passed comparator.
template<std::totally_ordered T>
void merge(
    std::vector<T>& data,
    const std::size_t left_index,
    const std::size_t middle_index,
    const std::size_t right_index,
    bool(* comparator)(const T, const T))
{
    std::size_t left_size{middle_index - left_index + 1};
    std::size_t right_size{right_index - middle_index};

    std::vector<T> left_data(left_size);
    std::vector<T> right_data(right_size);

    for (std::size_t i = 0; i < left_size; ++i)
        left_data[i] = data[left_index + i];

    for (std::size_t i = 0; i < right_size; ++i)
        right_data[i] = data[middle_index + 1 + i];

    for (std::size_t i = 0, j = 0, k = left_index; i < left_size || j < right_size; ++k) {
        if ((j >= right_size) || ((i < left_size) && comparator(left_data[i], right_data[j])))
            data[k] = left_data[i++];
        else
            data[k] = right_data[j++];
    }
}

} // namespace

/// @brief Sorts vector.
///
/// @tparam T          Type of vector element.
/// @param data        Vector to sort.
/// @param left_index  Start sorting index.
/// @param right_index End sorting index.
/// @param st          Type of sorting.
/// @return            true if sorted otherwise false.
///
/// @see https://en.wikipedia.org/wiki/Merge_sort
///
template<std::totally_ordered T>
bool merge_sort(
    std::vector<T>& data,
    const std::size_t left_index,
    const std::size_t right_index,
    const sorting_type st = sorting_type::ascending)
{
    auto size = data.size();

    if (size < 2) {
        return false;
    }
    if (left_index >= right_index) {
        return false;
    }
    auto middle_index = left_index + (right_index - left_index) / 2;

    merge_sort(data, left_index, middle_index, st);
    merge_sort(data, middle_index + 1, right_index, st);

    if (st == sorting_type::ascending) {
        merge(data, left_index, middle_index, right_index, std::cmp_less_equal);
    } else {
        merge(data, left_index, middle_index, right_index, std::cmp_greater_equal);
    }
    return true;
}

/// @brief Sorts vector.
///
/// @tparam T   Type of vector element.
/// @param data Vector to sort.
/// @param st   Type of sorting.
/// @return     true if sorted otherwise false.
///
/// @see https://en.wikipedia.org/wiki/Merge_sort
///
template<std::totally_ordered T>
bool merge_sort(std::vector<T>& data, const sorting_type st = sorting_type::ascending) {
    return merge_sort(data, 0, data.size() - 1, st);
}

} // namespace wingmann::algorithms::sorting

#endif // WINGMANN_ALGORITHMS_SORTING_MERGE_SORT_H
