/// @file   z_function.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Z-function substring searching algorithm implementation.
/// @date   2022-10-13
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_STRINGS_Z_FUNCTION_H
#define WINGMANN_ALGORITHMS_STRINGS_Z_FUNCTION_H

#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace wingmann::algorithms::strings {

namespace {

// Generates the Z-function for the inputted string.
auto generate_z_func = [](const std::string& pattern)
{
    auto length = pattern.size();
    std::vector<uint64_t> z_values(length, 0);

    for (std::size_t i = 1, l = 0, r = 0; i < length; ++i) {
        if (i <= r)
            z_values[i] = std::min(r - i + 1, z_values[i - l]);

        while ((i + z_values[i] < length) && (pattern[z_values[i]] == pattern[i + z_values[i]]))
            z_values[i]++;

        if (i + z_values[i] - 1 > r)
            r = i + z_values[i] - 1;
    }
    return z_values;
};

} // namespace

/// @brief Using Z-function to find a pattern in a text
///
/// @param text    Text in which to search
/// @param pattern String pattern to search.
/// @return        Vector of starting indexes where pattern is found in the text.
///
/// @see https://cp-algorithms.com/string/z-function.html
///
std::vector<std::uint64_t> z_func_substr(const std::string& text, const std::string& pattern)
{
    auto text_length = text.size();
    auto pattern_length = pattern.size();

    std::stringstream data;
    data << pattern << '#' << text;

    auto z = generate_z_func(data.str());
    std::vector<std::uint64_t> matched_indexes;

    for (std::size_t i = 0; i < text_length; ++i)
        if (z[i + pattern_length + 1] == pattern_length)
            matched_indexes.emplace_back(i);

    return matched_indexes;
}

} // namespace wingmann::algorithms::strings

#endif // WINGMANN_ALGORITHMS_STRINGS_Z_FUNCTION_H
