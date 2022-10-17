#include <algorithms/strings/knuth_morris_pratt.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::strings;

TEST(algorithms_strings, knuth_morris_pratt_found)
{
    auto text{"A string-matching algorithm wants to find the starting index"};
    EXPECT_TRUE(kmp(text, "ring-match"));
}

TEST(algorithms_strings, knuth_morris_pratt_not_found)
{
    auto text{"A string-matching algorithm wants to find the starting index"};
    EXPECT_FALSE(kmp(text, "hctam-gnir"));
}
