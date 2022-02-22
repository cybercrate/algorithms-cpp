#ifndef WINGALGO_SEARCH_LINEAR_SEARCH_H
#define WINGALGO_SEARCH_LINEAR_SEARCH_H

/// \file
/// \brief [Linear search algorithm](https://en.wikipedia.org/wiki/Linear_search)

#include <cstddef>
#include <vector>

namespace wing::search {

/// Finds value in vector.
/// @tparam T Generic type of vector.
/// @param data Vector to be searched in.
/// @param value Value to be searched.
/// @return Index of the value if it is in the vector, otherwise -1.
template<typename T>
std::size_t linear_search(const std::vector<T>& data, const T&& value)
{
    if (data.empty())
        return static_cast<std::size_t>(-1);

    for (auto i = 0; i < data.size(); ++i)
        if (data[i] == value)
            return i;

    return static_cast<std::size_t>(-1);
}

} // namespace wing::search

#endif // WINGALGO_SEARCH_LINEAR_SEARCH_H
