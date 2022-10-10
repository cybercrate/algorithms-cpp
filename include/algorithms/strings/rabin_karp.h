/// @file   rabin_karp.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Rabin-Karp substring searching algorithm implementation.
/// @date   2022-10-11
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_STRINGS_RABIN_KARP_H
#define WINGMANN_ALGORITHMS_STRINGS_RABIN_KARP_H

#include <cmath>
#include <optional>
#include <string>

namespace wingmann::algorithms::strings {

namespace {

// Converts a string to an integer.
auto create_hash = [](const std::string& text, int count)
{
    const auto prime{5};
    std::int64_t result{};

    for (int i = 0; i < count; ++i)
        result += static_cast<std::int64_t>(text[i] * static_cast<std::int64_t>(pow(prime, i)));

    return result;
};

// Re-hash a string using known existing hash.
auto recalculate_hash = [](
    const std::string& text,
    std::size_t index,
    std::size_t new_index,
    std::int64_t hash,
    std::size_t pattern_length)
{
    const auto prime{5};

    auto new_hash = hash - text[index];
    new_hash /= prime;
    new_hash += static_cast<std::int64_t>(
        text[new_index] * static_cast<std::int64_t>(pow(prime, pattern_length - 1)));

    return new_hash;
};

// Compare if two sub-strings are equal.
auto check_for_equal = [](
    const std::string& first_text,
    const std::string& second_text,
    std::size_t first_start,
    std::size_t first_end,
    std::size_t second_start,
    std::size_t second_end)
{
    if ((first_end - first_start) != (second_end - second_start))
        return false;

    while ((first_end > first_start) && (second_end > second_start)) {
        if (first_text[first_start] != second_text[second_start])
            return false;

        ++first_start;
        ++second_start;
    }
    return true;
};

} // namespace

/// @brief Perform string pattern search using Rabin-Karp algorithm.
///
/// @param str String to search in.
/// @param pat Pattern to search for.
/// @return    Index of the found pattern or std::nullopt if not found.
///
/// @see https://en.wikipedia.org/wiki/Rabin-Karp_algorithm
///
std::optional<std::size_t> rabin_karp(const std::string& text, const std::string& pattern)
{
    auto pat_hash = create_hash(pattern, pattern.size());
    auto str_hash = create_hash(text, pattern.size());

    for (std::size_t i = 0; i <= (text.size() - pattern.size()); ++i) {
        auto equal = check_for_equal(text, pattern, i, i + pattern.size() - 1, 0, pattern.size() - 1);

        if ((pat_hash == str_hash) && equal)
            return i;

        if (i < text.size() - pattern.size())
            str_hash = recalculate_hash(text, i, i + pattern.size(), str_hash, pattern.size());
    }
    return std::nullopt;
}

} // namespace wingmann::algorithms::strings

#endif // WINGMANN_ALGORITHMS_STRINGS_RABIN_KARP_H
