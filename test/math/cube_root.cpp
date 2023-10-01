#include <algorithms/math/cube_root.h>
#include <gtest/gtest.h>
#include <string>

TEST(algorithms_math, cube_root_1) {
    auto x = wingmann::algorithms::math::cube_root(262'144);
    auto y = static_cast<int>(std::cbrt(262'144));

    EXPECT_EQ(std::to_string(x), std::to_string(y));
}

TEST(algorithms_math, cube_root_2) {
    auto x = wingmann::algorithms::math::cube_root(2'126'781.656f);
    auto y = std::cbrt(2'126'781.656f);

    EXPECT_EQ(std::to_string(x), std::to_string(y));
}

TEST(algorithms_math, cube_root_3) {
    auto x = wingmann::algorithms::math::cube_root(35'611.289);
    auto y = std::cbrt(35'611.289);

    EXPECT_EQ(std::to_string(x), std::to_string(y));
}
