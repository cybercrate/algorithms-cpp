#include "data_structures.h"

#include "gtest/gtest.h"

TEST(list, empty)
{
    auto list = new wing::algo::list<int>{};

    EXPECT_TRUE(list->isEmpty());
    EXPECT_EQ(0, list->size());
}

TEST(list, from_node)
{
    auto node = wing::algo::list<int>::node_type{7};
    node.link = new wing::algo::list<int>::node_type{9};

    auto list = new wing::algo::list<int>{&node};

    EXPECT_FALSE(list->isEmpty());
    EXPECT_EQ(2, list->size());
}

TEST(list, add_element)
{
    auto list = new wing::algo::list<int>{};

    list->add(7);
    list->add(5);

    EXPECT_EQ(2, list->size());
}

TEST(list, add_node)
{
    auto list = new wing::algo::list<int>{};

    list->add(7);
    list->add(5);

    auto node = wing::algo::list<int>::node_type{1, nullptr};

    list->add(&node);

    EXPECT_EQ(3, list->size());
}

TEST(list, remove_element)
{
    auto list = new wing::algo::list<int>{};
    list->add(8);
    list->add(2);
    list->add(1);
    list->add(3);

    EXPECT_EQ(4, list->size());

    list->remove(1);
    list->remove(1);

    EXPECT_EQ(2, list->size());
}

TEST(list, get_element)
{
    auto list = new wing::algo::list<int>{};
    list->add(7);
    list->add(5);
    list->add(1);
    list->add(6);
    list->add(1);
    list->add(0);
    list->add(3);
    list->add(4);
    list->add(4);
    list->add(2);
    list->add(8);

    EXPECT_EQ(6, list->get(3));
}

TEST(list, set_element)
{
    auto list = new wing::algo::list<int>{};
    list->add(1);
    list->add(4);
    list->add(1);
    list->add(6);
    list->add(1);
    list->add(7);
    list->add(3);
    list->add(4);
    list->add(9);
    list->add(2);
    list->add(8);

    EXPECT_EQ(7, list->get(5));

    list->set(5, 11);

    EXPECT_EQ(11, list->get(5));
}

TEST(list, get_begin)
{
    auto list = new wing::algo::list<int>{};
    list->add(1);
    list->add(2);
    list->add(9);

    EXPECT_EQ(1, list->begin());
}

TEST(list, get_end)
{
    auto list = new wing::algo::list<int>{};
    list->add(1);
    list->add(2);
    list->add(9);

    EXPECT_EQ(9, list->end());
}

TEST(list, destroy)
{
    auto list = new wing::algo::list<int>{};
    list->add(4);
    list->add(8);
    list->add(1);
    list->add(5);
    list->add(0);
    list->add(3);

    EXPECT_EQ(6, list->size());

    list->destroy();

    EXPECT_EQ(0, list->size());
    EXPECT_TRUE(list->isEmpty());
}
