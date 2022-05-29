#ifndef WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H

/**
 * @brief Binary search algorithm
 * @details
 * Binary search compares the target value to the middle element of the array.@n
 * If they are not equal, the half in which the target cannot lie is eliminated and the search
 * continues on the remaining half, again taking the middle element to compare to the target value,
 * and repeating this until the target value is found.@n
 * If the search ends with the remaining half being empty, the target is not in the array.@n
 * @complexities
 * Worst-case time complexity  O(log n)@n
 * Best-case time complexity   O(1)@n
 * Average time complexity	   O(log n)@n
 * Worst-case space complexity 0(1)@n
 * Where n is the number of element in the array.
 * @see https://en.wikipedia.org/wiki/Binary_search_algorithm
 */

#include "errors/search_error_kind.h"

#include <err_fusion.h>

#include <cstddef>
#include <vector>
#include <limits>

namespace wingmann::algorithms::search {

/**
 * @brief Finds value in vector.
 * @tparam T Generic type of vector.
 * @param data Vector to be searched in.
 * @param value Value to be searched.
 * @return
 * Index of the found item or Empty if the container item is empty or
 * NotFound if the item is not found.
 */
template<typename T>
auto binary_search(const std::vector<T>& data, const T&& value)
{
    if (data.empty())
        return ef::err<std::size_t, error::SearchError>(error::SearchError::Empty);

    // Set lowest point of the vector.
    std::size_t low{};
    // Set the highest point of the vector.
    std::size_t high{data.size() - 1};

    std::size_t current;
    std::size_t index;

    while (low <= high) {
        // Set the pivot point.
        index = low + (high - low) / 2;
        current = data.at(index);

        // If pivot point is the value, return it, else check if val is greater or smaller than
        // pivot value and set the next pivot point accordingly.
        if (value == current)
            return ef::ok<std::size_t, error::SearchError>(index);
        else if (value < current)
            high = index - 1;
        else
            low = index + 1;
    }
    // If vector does not contain a value, return -1.
    return ef::err<std::size_t, error::SearchError>(error::SearchError::NotFound);
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H
