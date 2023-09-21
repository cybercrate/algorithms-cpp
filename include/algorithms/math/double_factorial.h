/// @file   double_factorial.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Double factorial functions.
/// @date   2022-10-21
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_MATH_DOUBLE_FACTORIAL_H
#define WINGMANN_ALGORITHMS_MATH_DOUBLE_FACTORIAL_H

#include <concepts>
#include <cmath>
#include <optional>

namespace wingmann::algorithms::math {

/// @brief Computes double factorial of number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Double factorial of value.
///
/// @see https://en.wikipedia.org/wiki/Double_factorial
///
template<std::integral T>
T double_factorial(T value) {
    return (value <= 1) ? 1 : value * double_factorial<T>(value - 2);
}

/// @brief Computes double factorial of number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Double factorial of value.
///
/// @see https://en.wikipedia.org/wiki/Double_factorial
///
template<std::integral T>
T double_factorial_loop(T value) {
    T result{1};

    if (value <= 1) {
        return result;
    }
    for (std::size_t i = value; ; i -= 2) {
        if (i == 0 || i == 1) {
            return result;
        }
        result *= i;
    }
}

} // namespace wingmann::algorithms::math

#endif // WINGMANN_ALGORITHMS_MATH_DOUBLE_FACTORIAL_H
