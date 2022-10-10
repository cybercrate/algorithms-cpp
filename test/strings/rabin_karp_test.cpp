#include <algorithms/strings/rabin_karp.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::strings;

TEST(algorithms_strings, rabin_karp_found)
{
    auto text{"A string-matching algorithm wants to find the starting index"};

    auto result = rabin_karp(text, "ring-match");

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value(), 4);
}

TEST(algorithms_strings, rabin_karp_not_found)
{
    auto text{"A string-matching algorithm wants to find the starting index"};

    EXPECT_FALSE(rabin_karp(text, "hctam-gnir").has_value());
}
