#ifndef WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H
#define WINGMANN_ALGORITHMS_SEARCH_FIBONACCI_SEARCH_H

/**
 * @brief Fibonacci search algorithm.
 * @details
 * The Fibonacci search technique is a method of searching a sorted array using a divide and
 * conquer algorithm that narrows down possible locations with the aid of Fibonacci numbers.@n
 * Compared to binary search where the sorted array is divided into two equal-sized parts,
 * one of which is examined further, Fibonacci search divides the array into two parts that have
 * sizes that are consecutive Fibonacci numbers.@n
 * On average, this leads to about 4% more comparisons to be executed,
 * but it has the advantage that one only needs addition and subtraction to calculate the
 * indices of the accessed array elements, while classical binary search needs bit-shift,
 * division or multiplication, operations that were less common at the time Fibonacci search
 * was first published.@n
 * Fibonacci search has an average- and worst-case complexity of O(log n).@n
 * The Fibonacci sequence has the property that a number is the sum of its two predecessors.@n
 * Therefore the sequence can be computed by repeated addition.@n
 * The ratio of two consecutive numbers approaches the Golden ratio, 1.618...@n
 * Binary search works by dividing the seek area in equal parts (1:1).@n
 * Fibonacci search can divide it into parts approaching 1:1.618 while using the
 * simpler operations.@n
 * If the elements being searched have non-uniform access memory storage
 * (i. e., the time needed to access a storage location varies depending on the location accessed),
 * the Fibonacci search may have the advantage over binary search in slightly reducing the average
 * time needed to access a storage location.@n
 * If the machine executing the search has a direct mapped CPU cache,
 * binary search may lead to more cache misses because the elements that are accessed often
 * tend to gather in only a few cache lines; this is mitigated by splitting the array in parts that
 * do not tend to be powers of two.@n
 * If the data is stored on a magnetic tape where seek time depends on the current head position,
 * a tradeoff between longer seek time and more comparisons may lead to a search algorithm that
 * is skewed similarly to Fibonacci search.@n
 * Fibonacci search is derived from Golden section search, an algorithm by Jack Kiefer (1953)
 * to search for the maximum or minimum of a uni-modal function in an interval.
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
