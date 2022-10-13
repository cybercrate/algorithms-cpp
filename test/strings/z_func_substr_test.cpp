#include <algorithms/strings/z_func_substr.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::strings;

TEST(algorithms_strings, z_func_substr_found)
{
    std::string text{"qweabcrtyuioabcpasabcaavbcadfgabchjklzxcvbnabcbama"};
    std::string pattern{"abc"};

    auto matched_indexes = z_func_substr(text, pattern);
    auto expected = std::vector<std::size_t>{3, 12, 18, 30, 43};

    EXPECT_EQ(matched_indexes, expected);
}

TEST(algorithms_strings, z_func_substr_not_found)
{
    std::string text{"qwerty"};
    std::string pattern{"abc"};

    auto matched_indexes = z_func_substr(text, pattern);
    auto expected = std::vector<std::size_t>{};

    EXPECT_EQ(matched_indexes, expected);
}
