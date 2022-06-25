#ifndef WINGMANN_ALGORITHMS_TEST_SEARCH_SEARCH_TEST_HELPERS_H
#define WINGMANN_ALGORITHMS_TEST_SEARCH_SEARCH_TEST_HELPERS_H

#include <vector>
#include <memory>
#include <random>
#include <chrono>
#include <concepts>
#include <algorithm>
#include <tuple>
#include <utility>

template<typename T>
requires std::integral<T>
T get_random_value(int min = 1, int max = 1'000)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    auto engine = std::default_random_engine(seed);

    return std::uniform_int_distribution<T>{min, max}(engine);
}

template<typename T>
requires std::integral<T>
std::vector<T> get_sorted_vector_with_random_values(std::size_t count = 10'000)
{
    std::vector<T> data(count);

    for (std::size_t i = 0; i < count; ++i)
        data[i] = get_random_value<T>();

    std::sort(data.begin(), data.end());

    return std::move(data);
}

template<typename T>
requires std::integral<T>
auto get_value(const std::vector<T>& data)
{
    auto index = get_random_value<T>(0, data.size() - 1);
    auto value = data[index];

    return value;
}

template<typename T>
requires std::integral<T>
auto get_values(const std::vector<T>& data)
{
    auto index = get_random_value<T>(0, data.size() - 1);
    auto value = data[index];

    return std::make_pair(index, value);
}

#endif // WINGMANN_ALGORITHMS_TEST_SEARCH_SEARCH_TEST_HELPERS_H
