#ifndef WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H

/**
 * @brief Linear search algorithm
 * @details
 * A linear search runs in at worst linear time and makes at most n comparisons,
 * where n is the length of the list.@n
 * If each element is equally likely to be searched,
 * then linear search has an average case of (n+1)/2 comparisons,
 * but the average case can be affected if the search probabilities for each element vary.@n
 * Linear search is rarely practical because other search algorithms and schemes,
 * such as the binary search algorithm and hash tables,
 * allow significantly faster searching for all but short lists.
 * @see https://en.wikipedia.org/wiki/Linear_search
 */

#include <cstddef>
#include <vector>
#include <limits>

namespace wingmann::algorithms::search {

/**
 * Finds value in vector.
 * @tparam T Generic type of vector.
 * @param data Vector to be searched in.
 * @param value Value to be searched.
 * @return Index of the value if it is in the vector, otherwise -1.
 */
template<typename T>
std::size_t linear_search(const std::vector<T>& data, const T&& value)
{
    if (data.empty())
        return std::numeric_limits<std::size_t>::max();

    for (auto i = 0; i < data.size(); ++i)
        if (data[i] == value)
            return i;

    return std::numeric_limits<std::size_t>::max();
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H
