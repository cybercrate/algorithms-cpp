/// @file   fibonacci.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Fibonacci functions.
/// @date   2022-10-07
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#include <concepts>

#ifndef WINGMANN_ALGORITHMS_MATH_FIBONACCI_H
#define WINGMANN_ALGORITHMS_MATH_FIBONACCI_H

namespace wingmann::algorithms::math {

/// @brief Recursively computes fibonacci number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Fibonacci number.
///
/// @see https://en.wikipedia.org/wiki/Fibonacci_number
///
template<typename T>
T fibonacci(T value) requires std::integral<T> && (!std::same_as<T, bool>)
{
    return (value <= 1) ? value : fibonacci(value - 1) + fibonacci(value - 2);
}

/// @brief Computes fibonacci number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Fibonacci number.
///
/// @see https://en.wikipedia.org/wiki/Fibonacci_number
///
template<typename T>
T fibonacci_loop(T value) requires std::integral<T> && (!std::same_as<T, bool>)
{
    T first{};
    T second{1};
    T next;

    for (std::size_t i = 3; i <= value + 1; ++i) {
        next = first + second;
        first = second;
        second = next;
    }
    return next;
}

} // namespace wingmann::algorithms::math

#endif // WINGMANN_ALGORITHMS_MATH_FIBONACCI_H
