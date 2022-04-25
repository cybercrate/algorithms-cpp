#include "data_structures.h"

#include "gtest/gtest.h"

namespace ds = wingmann::algorithms::data_structures;

TEST(data_structures_list, empty)
{
    auto list = new ds::list<int>{};

    EXPECT_TRUE(list->is_empty());
    EXPECT_EQ(0, list->size());
}

TEST(data_structures_list, from_node)
{
    auto node = ds::list<int>::node_type{7};
    node.link = new ds::list<int>::node_type{9};

    auto list = new ds::list<int>{&node};

    EXPECT_FALSE(list->is_empty());
    EXPECT_EQ(2, list->size());
}

TEST(data_structures_list, add_element)
{
    auto list = new ds::list<int>{};

    list->add(7);
    list->add(5);

    EXPECT_EQ(2, list->size());
}

TEST(data_structures_list, add_node)
{
    auto list = new ds::list<int>{};

    list->add(7);
    list->add(5);

    auto node = ds::list<int>::node_type{1, nullptr};

    list->add(&node);

    EXPECT_EQ(3, list->size());
}

TEST(data_structures_list, remove_element)
{
    auto list = new ds::list<int>{};
    list->add(8);
    list->add(2);
    list->add(1);
    list->add(3);

    EXPECT_EQ(4, list->size());

    list->remove(1);
    list->remove(1);

    EXPECT_EQ(2, list->size());
}

TEST(data_structures_list, get_element)
{
    auto list = new ds::list<int>{};
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

TEST(data_structures_list, set_element)
{
    auto list = new ds::list<int>{};
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

TEST(data_structures_list, get_begin)
{
    auto list = new ds::list<int>{};
    list->add(1);
    list->add(2);
    list->add(9);

    EXPECT_EQ(1, list->begin());
}

TEST(data_structures_list, get_end)
{
    auto list = new ds::list<int>{};
    list->add(1);
    list->add(2);
    list->add(9);

    EXPECT_EQ(9, list->end());
}

TEST(data_structures_list, destroy)
{
    auto list = new ds::list<int>{};
    list->add(4);
    list->add(8);
    list->add(1);
    list->add(5);
    list->add(0);
    list->add(3);

    EXPECT_EQ(6, list->size());

    list->destroy();

    EXPECT_EQ(0, list->size());
    EXPECT_TRUE(list->is_empty());
}
