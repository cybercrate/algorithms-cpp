/// @file   cube_root.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Cube root functions.
/// @date   2022-10-08
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_MATH_CUBE_ROOT_H
#define WINGMANN_ALGORITHMS_MATH_CUBE_ROOT_H

#include <cmath>
#include <concepts>

namespace wingmann::algorithms::math {

/// @brief Computes cube root.
///
/// @tparam T    Type of a number.
/// @param value A number.
/// @return      Cube root of number.
///
/// @see https://en.wikipedia.org/wiki/Cube_root
///
template<typename T>
requires std::floating_point<T> || (std::integral<T> && (!std::same_as<T, bool>))
T cube_root(T value)
{
    // Set precision.
    const auto epsilon{0.0000001};
    const auto doubled_value = static_cast<double>(value);

    // Set begin and end for binary search
    double begin{};
    double end = doubled_value;

    while (true) {
        double middle = (begin + end) / 2;

        // Absolute value of value - pow(middle, 3)
        double error = [](double value, double middle) {
            auto middle_powered = std::pow(middle, 3);
            return (value > middle_powered)
                ? value - middle_powered
                : middle_powered - value;
        }(doubled_value, middle);

        if (epsilon > error) return static_cast<T>(middle);

        // If pow(middle, 3) is greater than value set end = middle
        if (std::pow(middle, 3) > doubled_value)
            end = middle;
        // If pow(middle, 3) is less than value set begin = middle
        else
            begin = middle;
    }
}

} // namespace wingmann::algorithms::math

#endif // WINGMANN_ALGORITHMS_MATH_CUBE_ROOT_H
