#ifndef WINGMANN_ALGORITHMS_STRINGS_KNUTH_MORRIS_PRATT_H
#define WINGMANN_ALGORITHMS_STRINGS_KNUTH_MORRIS_PRATT_H

/**
 * @brief Knuth-Morris-Pratt substring searching algorithm implementation.
 * @see https://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
 */

#include <vector>
#include <string>

namespace wingmann::algorithms::strings {

/**
 * @brief KMP algorithm to find a pattern in a text.
 * @param text Text in which to search.
 * @param pattern String pattern to search.
 * @return Search result.
 */
bool kmp(const std::string& text, const std::string& pattern)
{
    auto text_size = text.size();
    auto pattern_size = pattern.size();

    // Get failure array.
    auto failure = [](const std::string& pattern) {
        auto pattern_size = pattern.size();
        auto failure = std::vector<std::size_t>(pattern_size + 1);
        failure[0] = -1;

        for (std::size_t i = 0, j = failure[0]; i < pattern_size; i++) {
            while ((j != -1) && (pattern[j] != pattern[i]))
                j = failure[j];

            failure[i + 1] = ++j;
        }
        return failure;
    }(pattern);

    for (std::size_t i = 0, j = 0; i < text_size; i++) {
        while ((j != -1) && (pattern[j] != text[i]))
            j = failure[j];

        if (++j == pattern_size) return true;
    }
    return false;
}

} // namespace wingmann::algorithms::strings

#endif // WINGMANN_ALGORITHMS_STRINGS_KNUTH_MORRIS_PRATT_H
