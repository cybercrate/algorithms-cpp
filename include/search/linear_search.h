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

#include "errors/search_error_kind.h"

#include <err_fusion.h>

#include <cstddef>
#include <vector>
#include <limits>

namespace wingmann::algorithms::search {

/**
 * Finds value in vector.
 * @tparam T Generic type of vector.
 * @param data Vector to be searched in.
 * @param value Value to be searched.
 * @return
 * Index of the found item or Empty if the container item is empty or
 * NotFound if the item is not found.
 */
template<typename T>
auto linear_search(const std::vector<T>& data, const T&& value)
{
    if (data.empty())
        return ef::err<std::size_t, error::SearchError>(error::SearchError::Empty);

    for (std::size_t i = 0; i < data.size(); ++i)
        if (data[i] == value)
            return ef::ok<std::size_t, error::SearchError>(i);

    return ef::err<std::size_t, error::SearchError>(error::SearchError::NotFound);
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H
