#ifndef WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H

/**
 * @brief Fibonacci search algorithm implementation.
 * @see https://en.wikipedia.org/wiki/Fibonacci_search_technique
 */

#include <cmath>
#include <optional>
#include <vector>
#include <concepts>

namespace wingmann::algorithms::search {

/**
 * @brief Finds value in vector.
 * @tparam T Generic type of vector.
 * @param data Vector to be searched in.
 * @param value Value to be searched.
 * @return Index of the found item or std::nullopt if not found.
 */
template<typename T>
requires std::totally_ordered<T>
std::optional<std::size_t> fibonacci_search(const std::vector<T>& data, const T& target)
{
    if (data.empty()) return std::nullopt;

    std::size_t last{};
    std::size_t current{1};

    auto next{last + current};
    auto size = data.size();

    while (next < size) {
        last = current;
        current = next;
        next = last + current;
    }
    int offset = -1;
    std::size_t index;

    while (next > 1) {
        index = std::min(offset + last, size - 1);

        if (data[index] < target) {
            next = current;
            current = last;
            last = next - current;
            offset = static_cast<int>(index);
        }
        else if (data[index] > target) {
            next = last;
            current = current - last;
            last = next - current;
        }
        else {
            return index;
        }
    }

    if (current && (data[offset + 1] == target))
        return offset + 1;
    else
        return std::nullopt;
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H
