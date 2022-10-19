/// @file   factorial.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Factorial functions.
/// @date   2022-10-02
/// 
/// @copyright Copyright (c) 2022
/// 
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#include <wing_concepts/numeric_concepts.h>

#ifndef WINGMANN_ALGORITHMS_MATH_FACTORIAL_H
#define WINGMANN_ALGORITHMS_MATH_FACTORIAL_H

namespace wingmann::algorithms::math {

/// @brief Recursively computes factorial of number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Factorial of value.
///
/// @see https://en.wikipedia.org/wiki/Factorial
///
template<wingmann::concepts::numeric::integral_number T>
T factorial(T value)
{
    return (value <= 0) ? 1 : value * factorial(value - 1);
}

/// @brief Computes factorial of number.
///
/// @tparam T    Integral type.
/// @param value An integral value.
/// @return      Factorial of value.
///
/// @see https://en.wikipedia.org/wiki/Factorial
///
template<wingmann::concepts::numeric::integral_number T>
T factorial_loop(T value)
{
    T result{1};

    for (int i = value; i >= 1; --i)
        result *= i;

    return result;
}

} // namespace wingmann::algorithms::math

#endif // WINGMANN_ALGORITHMS_MATH_FACTORIAL_H
