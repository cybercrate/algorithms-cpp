/// @file   jump_search.h
/// @brief  Jump search algorithm implementation.
/// @author Alexander Shavrov

#ifndef WINGMANN_ALGORITHMS_SEARCH_JUMP_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_JUMP_SEARCH_H

#include <cmath>
#include <optional>
#include <vector>
#include <concepts>

namespace wingmann::algorithms::search {

/// @brief Finds value in vector.
///
/// @tparam T    Generic type of vector.
/// @param data  Vector to be searched in.
/// @param value Value to be searched.
/// @return      Index of the found item or std::nullopt if not found.
///
/// @see https://en.wikipedia.org/wiki/Jump_search
///
template<std::totally_ordered T>
std::optional<std::size_t> jump_search(const std::vector<T>& data, const T& target)
{
    if (data.empty())
        return std::nullopt;

    std::size_t jump_step = std::floor(std::sqrt(data.size()));
    std::size_t current_index{};
    std::size_t next_index = jump_step;
    std::size_t size = data.size();

    while (data[next_index - 1] < target) {
        current_index = next_index;
        next_index += jump_step;

        if (next_index >= size) {
            next_index = size - 1;
            break;
        }
    }

    for (std::size_t i = current_index; i <= next_index; i++)
        if (data[i] == target) return i;

    return std::nullopt;
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_JUMP_SEARCH_H
