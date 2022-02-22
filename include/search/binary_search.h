#ifndef WINGALGO_SEARCH_BINARY_SEARCH_H
#define WINGALGO_SEARCH_BINARY_SEARCH_H

/// @file
/// @brief [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
/// @details
/// Binary search is a search algorithm that finds the position of a target value within a sorted array.
/// Binary search compares the target value to the middle element of the array.
/// If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the
/// remaining half, again taking the middle element to compare to the target value, and repeating this until the
/// target value is found.
/// If the search ends with the remaining half being empty, the target is not in the array.
///
/// Implementation:
/// Binary search works on sorted arrays. Binary search begins by comparing an element in the middle of the array
/// with the target value.
/// If the target value matches the element, its position in the array is returned.
/// If the target value is less than the element, the search continues in the lower half of the array.
/// If the target value is greater than the element, the search continues in the upper half of the array.
/// By doing this, the algorithm eliminates the half in which the target value cannot lie in each iteration.
///
/// Complexities:
/// Worst-case time complexity  O(log n)
/// Best-case time complexity   O(1)
/// Average time complexity	    O(log n)
/// Worst-case space complexity 0(1)
/// Where n is the number of element in the array.

#include <cstddef>
#include <vector>

namespace wing::search {

/// Finds value in vector.
/// @tparam T Generic type of vector.
/// @param data Vector to be searched in.
/// @param value Value to be searched.
/// @return Index of the value if it is in the vector, otherwise -1.
template<typename T>
std::size_t binary_search(const std::vector<T>& data, const T&& value)
{
    if (data.empty())
        return static_cast<std::size_t>(-1);

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

        // If pivot point is the value, return it,
        // else check if val is greater or smaller than pivot value and set the next pivot point accordingly.

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

} // namespace wing::search

#endif // WINGALGO_SEARCH_BINARY_SEARCH_H
