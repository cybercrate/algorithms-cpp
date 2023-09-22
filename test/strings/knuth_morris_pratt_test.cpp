#include <algorithms/strings/knuth_morris_pratt.h>
#include <gtest/gtest.h>

TEST(algorithms_strings, knuth_morris_pratt_found) {
    auto text{"A string-matching algorithm wants to find the starting index"};
    EXPECT_TRUE(wingmann::algorithms::strings::kmp(text, "ring-match"));
}

TEST(algorithms_strings, knuth_morris_pratt_not_found) {
    auto text{"A string-matching algorithm wants to find the starting index"};
    EXPECT_FALSE(wingmann::algorithms::strings::kmp(text, "hctam-gnir"));
}
