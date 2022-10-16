/// @file   sorting_type.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Sorting type flags enumeration.
/// @date   2022-10-14
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_SORTING_SORTING_TYPE_H
#define WINGMANN_ALGORITHMS_SORTING_SORTING_TYPE_H

#include <cstdint>

namespace wingmann::algorithms::sorting {

/// @brief Sorting type flags.
enum class sorting_type : std::uint8_t {
    ascending,
    descending
};

} // namespace wingmann::algorithms::sorting

#endif // WINGMANN_ALGORITHMS_SORTING_SORTING_TYPE_H
