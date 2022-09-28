#include <algorithms/containers.h>

#include <gtest/gtest.h>

using list_type = wingmann::algorithms::containers::list<int>;

TEST(list, empty) {
    list_type list{};

    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(0, list.size());
}

TEST(list, add_element) {
    list_type list{};
    list.insert(7);
    list.insert(5);

    EXPECT_EQ(2, list.size());
}

TEST(list, remove_node) {
    list_type list{};
    list.insert(8);
    list.insert(2);
    list.insert(1);
    list.insert(3);

    EXPECT_EQ(4, list.size());

    list.delete_node(1);

    EXPECT_EQ(3, list.size());
}

TEST(list, get_front) {
    list_type list{};
    list.insert(1);
    list.insert(2);
    list.insert(9);

    EXPECT_EQ(1, list.front());
}

TEST(list, get_back) {
    list_type list{};
    list.insert(1);
    list.insert(2);
    list.insert(9);

    EXPECT_EQ(9, list.back());
}

TEST(list, destroy) {
    list_type list{};
    list.insert(4);
    list.insert(8);
    list.insert(1);
    list.insert(5);
    list.insert(0);
    list.insert(3);

    EXPECT_EQ(6, list.size());

    list.destroy();

    EXPECT_EQ(0, list.size());
    EXPECT_TRUE(list.is_empty());
}
