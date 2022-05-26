#ifndef WINGMANN_ALGORITHMS_SORTING_BUBBLE_SORT_H
#define WINGMANN_ALGORITHMS_SORTING_BUBBLE_SORT_H

#include <vector>
#include <cstddef>
#include <utility>

/**
 * @brief Bubble sort algorithm
 * @details
 * This is a simple sorting algorithm that repeatedly steps through the list,
 * compares adjacent elements and swaps them if they are in the wrong order.@n
 * The pass through the list is repeated until the list is sorted.@n
 * The algorithm, which is a comparison sort,
 * is named for the way smaller or larger elements "bubble" to the top of the list.@n
 * This simple algorithm performs poorly in real world use and is used primarily as an
 * educational tool.
 * @complexity
 * Worst-case performance O(n^2)@n
 * Best-case performance  O(n)@n
 * Average performance    O(n^2)@n
 * Worst-case space complexity O(n) total, O(1)
 */

namespace wingmann::algorithms::sorting {

template<typename T>
void bubble_sort(std::vector<T>& data)
{
    if (data.empty()) return;

    bool swapped{true};
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
}

} // namespace wingmann::algorithms::sorting

#endif // WINGMANN_ALGORITHMS_SORTING_BUBBLE_SORT_H
