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

#include <concepts>
#include <vector>

namespace wingmann::algorithms::sorting {

/// @brief Sorts vector.
///
/// @tparam T   Type of vector element.
/// @param data Vector to sort.
///
/// @see https://en.wikipedia.org/wiki/Bubble_sort
///
template<typename T>
bool bubble_sort(std::vector<T>& data) requires std::totally_ordered<T> && std::swappable<T>
{
    if (data.size() <= 1)
        return false;

    bool swapped;
    auto size = data.size();

    for (std::size_t i = 0; i < size - 1; i++) {
        swapped = false;

        for (std::size_t j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return true;
}

} // namespace wingmann::algorithms::sorting

#endif // WINGMANN_ALGORITHMS_SORTING_BUBBLE_SORT_H
