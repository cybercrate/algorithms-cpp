/// @file   square_root.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Square root functions.
/// @date   2022-10-08
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_MATH_SQUARE_ROOT_H
#define WINGMANN_ALGORITHMS_MATH_SQUARE_ROOT_H

#include <wing_concepts/numeric_concepts.h>

#include <cmath>

namespace wingmann::algorithms::math {

/// @brief Computes square root.
///
/// @tparam T    Type of a number.
/// @param value A number.
/// @return      Square root of number.
///
/// @see https://en.wikipedia.org/wiki/Square_root
///
template<concepts::numeric::number T>
T square_root(T value)
{
    // Set precision.
    const auto epsilon{0.0000001};
    const auto doubled_value = static_cast<double>(value);

    auto low{0.0};
    auto high = static_cast<double>(doubled_value);

    auto result = (high + low) / 2.0;

    while (std::abs(std::pow(result, 2) - doubled_value) >= epsilon) {
        if (std::pow(result, 2) < doubled_value)
            low = result;
        else
            high = result;

        result = (high + low) / 2.0;
    }
    return static_cast<T>(result);
}

} // namespace wingmann::algorithms::math

#endif // WINGMANN_ALGORITHMS_MATH_SQUARE_ROOT_H
