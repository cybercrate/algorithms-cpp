/// @file   bubble_sort.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Bubble sort algorithm implementation.
/// @date   2022-10-02
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_SORTING_BUBBLE_SORT_H
#define WINGMANN_ALGORITHMS_SORTING_BUBBLE_SORT_H

#include "sorting_type.h"

#include <concepts>
#include <vector>

namespace wingmann::algorithms::sorting {

namespace {

// Sorts the vector using a passed comparator.
template<typename T>
requires std::totally_ordered<T> && std::swappable<T>
void bubble_sort(std::vector<T>& data, std::size_t size, bool(* comparator)(const T, const T))
{
    bool swapped;

    for (std::size_t i = 0; i < size - 1; ++i) {
        swapped = false;

        for (std::size_t j = 0; j < size - i - 1; ++j) {
            if (comparator(data[j], data[j + 1])) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) return;
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
/// @see https://en.wikipedia.org/wiki/Bubble_sort
///
template<typename T>
requires std::totally_ordered<T> && std::swappable<T>
bool bubble_sort(std::vector<T>& data, const sorting_type st = sorting_type::ascending)
{
    auto size = data.size();

    if (size < 2) return false;

    if (st == sorting_type::ascending)
        bubble_sort(data, size, std::cmp_greater);
    else
        bubble_sort(data, size, std::cmp_less);

    return true;
}

} // namespace wingmann::algorithms::sorting

#endif // WINGMANN_ALGORITHMS_SORTING_BUBBLE_SORT_H
