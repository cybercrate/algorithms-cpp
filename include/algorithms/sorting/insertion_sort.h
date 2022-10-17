/// @file   insertion_sort.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Insertion sort algorithm implementation.
/// @date   2022-10-17
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_SORTING_INSERTION_SORT_H
#define WINGMANN_ALGORITHMS_SORTING_INSERTION_SORT_H

#include "sorting_type.h"

#include <concepts>
#include <vector>

namespace wingmann::algorithms::sorting {

namespace {

template<std::totally_ordered T>
void insertion_sort(
    std::vector<T>& data,
    const std::size_t size,
    bool(* comparator)(const T, const T))
{
    std::int64_t j;

    for (std::size_t i = 1; i < size; ++i) {
        T temp = data[i];
        j = static_cast<int64_t>(i - 1);

        for (; j >= 0 && comparator(data[j], temp); --j)
            data[j + 1] = data[j];

        data[j + 1] = temp;
    }
}

} // namespace

/// @brief Sorts vector.
///
/// @tparam T   Type of vector element.
/// @param data Vector to sort.
/// @param st   Type of sorting.
/// @return     true if sorted otherwise false.
///
/// @see https://en.wikipedia.org/wiki/Insertion_sort
///
template<std::totally_ordered T>
bool insertion_sort(std::vector<T>& data, const sorting_type st = sorting_type::ascending)
{
    auto size = data.size();

    if (size < 2) return false;

    if (st == sorting_type::ascending)
        insertion_sort(data, size, std::cmp_greater);
    else
        insertion_sort(data, size, std::cmp_less);

    return true;
}

} // namespace wingmann::algorithms::sorting

#endif // WINGMANN_ALGORITHMS_SORTING_INSERTION_SORT_H
