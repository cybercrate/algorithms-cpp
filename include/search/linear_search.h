#ifndef WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H

/**
 * @brief Linear search algorithm implementation.
 * @see https://en.wikipedia.org/wiki/Linear_search
 */

#include <optional>
#include <cstddef>
#include <vector>
#include <limits>

namespace wingmann::algorithms::search {

/**
 * @brief Finds value in vector.
 * @tparam T Generic type of vector.
 * @param data Vector to be searched in.
 * @param value Value to be searched.
 * @return Index of the found item or std::nullopt if not found.
 */
template<typename T>
std::optional<std::size_t> linear_search(const std::vector<T>& data, const T& value)
{
    if (!data.empty()) {
        for (std::size_t i = 0; i < data.size(); ++i)
            if (data[i] == value)
                return i;
    }
    return std::nullopt;
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_LINEAR_SEARCH_H
