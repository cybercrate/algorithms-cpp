#ifndef WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H

/**
 * @brief Fibonacci search algorithm implementation.
 * @see https://en.wikipedia.org/wiki/Fibonacci_search_technique
 */

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstddef>

namespace wingmann::algorithms::search {

/**
 * @brief Using fibonacci search algorithm finds an index of a given element in a sorted collection.
 * @tparam T Generic type of collection elements.
 * @param data Array to search in.
 * @param target Search item.
 * @return
 * Index of the found item or Empty if the container item is empty or
 * NotFound if the item is not found.
 */
template<typename T>
auto fibonacci_search(const std::vector<T>& data, const T& target)
{
    if (data.empty()) return static_cast<std::size_t>(-1);

    std::size_t last{};
    std::size_t current{1};

    auto next{last + current};
    auto size = data.size();

    while(next < size) {
        last = current;
        current = next;
        next = last + current;
    }
    int offset = -1;
    std::size_t index;

    while(next > 1) {
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
    return (current && data[offset + 1] == target)
        ? offset + 1
        : static_cast<std::size_t>(-1);
}

} // namespace wingmann::algorithms::search

#endif // WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H
