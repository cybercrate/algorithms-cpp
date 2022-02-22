#ifndef ALGORITHMS_SEARCH_BINARY_SEARCH_H
#define ALGORITHMS_SEARCH_BINARY_SEARCH_H

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
/// Worst-case time complexity	O(log n)
/// Best-case time complexity	O(1)
/// Average time complexity	    O(log n)
/// Worst-case space complexity  0(1)
/// Where n is the number of element in the array.

#include <cstddef>
#include <vector>

/// @brief Finds value in data.
/// @param data Vector to be searched in.
/// @param value Value to be searched.
/// @return Index of the value if it is in the vector, otherwise -1.
std::size_t binary_search(const std::vector<int>& data, int value);

#endif // ALGORITHMS_SEARCH_BINARY_SEARCH_H
