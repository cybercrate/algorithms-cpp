#ifndef WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H

/**
 * @brief Binary search algorithm implementation.
 * @see https://en.wikipedia.org/wiki/Binary_search_algorithm
 */

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
    if (data.empty()) return static_cast<std::size_t>(-1);

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
            return index;
        else if (value < current)
            high = index - 1;
        else
            low = index + 1;
    }
    // If vector does not contain a value, return -1.
    return static_cast<std::size_t>(-1);
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_BINARY_SEARCH_H
