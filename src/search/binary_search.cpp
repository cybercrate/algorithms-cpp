#include "binary_search.h"

std::size_t binary_search(const std::vector<int>& data, int value)
{
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
    return -1;
}
