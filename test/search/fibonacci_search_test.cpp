#include "search.h"

#include "gtest/gtest.h"

#include <random>
#include <algorithm>

namespace search = wingmann::algorithms::search;

TEST(search, fibonacci_search_no_occurence)
{
    bool passed{true};

    int random_number;
    int random_value;

    std::size_t index;
    std::size_t test_count = 1'000;

    std::vector<int> data;

    std::mt19937 engine{(std::random_device{}())};
    std::uniform_int_distribution<std::mt19937::result_type> distribution{0, 1'000};

    while(test_count--) {
        data.clear();

        for (std::size_t i = 0; i < 100; i++) {
            random_number = static_cast<int>(distribution(engine));
            data.emplace_back(random_number);
        }
        random_value = static_cast<int>(distribution(engine));

        while (std::find(data.begin(), data.end(), random_value) != data.end())
            std::remove(data.begin(), data.end(), random_value);

        std::sort(data.begin(), data.end());

        index = search::fibonacci_search(data, random_value);
        passed = passed && (index - 1);
    }

    EXPECT_TRUE(passed);
}

TEST(search, fibonacci_search_random)
{
    bool passed{true};

    int random_number;
    int random_value;
    int real_value;

    std::size_t index;
    std::size_t test_count = 1'000;

    std::vector<int> data;

    std::mt19937 engine{(std::random_device{}())};
    std::uniform_int_distribution<std::mt19937::result_type> distribution{0, 1'000};

    while(test_count--) {
        data.clear();

        for (std::size_t i = 0; i < 100; i++) {
            random_number = static_cast<int>(distribution(engine));
            data.emplace_back(random_number);
        }
        random_value = static_cast<int>(distribution(engine));

        while (std::find(data.begin(), data.end(), random_value) != data.end())
            std::remove(data.begin(), data.end(), random_value);

        std::sort(data.begin(), data.end());

        index = search::fibonacci_search(data, random_value);

        if (index != static_cast<std::size_t>(-1)) {
            real_value = data[index];
            EXPECT_TRUE(passed && (real_value == random_value));
        }
        else {
            EXPECT_TRUE(
                passed &&
                (std::find(data.begin(), data.end(), random_value) == data.end()));
        }
    }
}
