#include <algorithms/strings.h>

#include <gtest/gtest.h>

using namespace wingmann::algorithms::strings;

auto text{"A string-matching algorithm wants to find the starting index"};

TEST(algorithms_strings, knuth_morris_pratt_found)
{
    EXPECT_TRUE(kmp(text, "ring-match"));
}

TEST(algorithms_strings, knuth_morris_pratt_not_found)
{
    EXPECT_FALSE(kmp(text, "hctam-gnir"));
}
