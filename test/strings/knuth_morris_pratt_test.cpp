#include "strings.h"

#include "gtest/gtest.h"

using namespace wingmann::algorithms::strings;

auto text{"A string-matching algorithm wants to find the starting index"};

TEST(knuth_morris_pratt, found)
{
    EXPECT_TRUE(kmp(text, "ring-match"));
}

TEST(knuth_morris_pratt, not_found)
{
    EXPECT_FALSE(kmp(text, "hctam-gnir"));
}
