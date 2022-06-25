#ifndef WINGMANN_ALGORITHMS_TEST_TEST_HELPERS_H
#define WINGMANN_ALGORITHMS_TEST_TEST_HELPERS_H

#include <concepts>
#include <chrono>
#include <random>

template<typename T>
requires std::integral<T>
T get_random_value(int min, int max)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    auto engine = std::default_random_engine(seed);

    return std::uniform_int_distribution<T>{min, max}(engine);
}

template<typename T>
requires std::integral<T>
std::vector<T>
get_vector_with_random_values(std::size_t count = 10'000, int min = 0, int max = 1'000)
{
    std::vector<T> data(count);

    for (std::size_t i = 0; i < count; ++i)
        data[i] = get_random_value<T>(min, max);

    return std::move(data);
}

template<typename T>
requires std::integral<T>
std::vector<T>
get_sorted_vector_with_random_values(std::size_t count = 10'000, int min = 0, int max = 1'000)
{
    auto data = get_vector_with_random_values<T>(count, min, max);
    std::sort(data.begin(), data.end());

    return std::move(data);
}

#endif // WINGMANN_ALGORITHMS_TEST_TEST_HELPERS_H
