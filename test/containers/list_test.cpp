#include "containers.h"

#include "gtest/gtest.h"

template<typename T>
using list_type = wingmann::algorithms::containers::list<T>;

template<typename T>
using list_node_type = typename wingmann::algorithms::containers::list<T>::list_node;

TEST(containers, list_empty)
{
    auto list = new list_type<int>{};

    EXPECT_TRUE(list->is_empty());
    EXPECT_EQ(0, list->size());
}

TEST(containers, list_from_node)
{
    auto node = list_node_type<int>{ 7};
    node.link = new list_node_type<int>{ 9};

    auto list = new list_type<int>{ &node};

    EXPECT_FALSE(list->is_empty());
    EXPECT_EQ(2, list->size());
}

TEST(containers, list_add_element)
{
    auto list = new list_type<int>{};

    list->add(7);
    list->add(5);

    EXPECT_EQ(2, list->size());
}

TEST(containers, list_add_node)
{
    auto list = new list_type<int>{};

    list->add(7);
    list->add(5);

    auto node = list_node_type<int>{ 1, nullptr};

    list->add(&node);

    EXPECT_EQ(3, list->size());
}

TEST(containers, list_remove_element)
{
    auto list = new list_type<int>{};
    list->add(8);
    list->add(2);
    list->add(1);
    list->add(3);

    EXPECT_EQ(4, list->size());

    list->remove(1);
    list->remove(1);

    EXPECT_EQ(2, list->size());
}

TEST(containers, list_get_element)
{
    auto list = new list_type<int>{};
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

TEST(containers, list_set_element)
{
    auto list = new list_type<int>{};
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

TEST(containers, list_get_begin)
{
    auto list = new list_type<int>{};
    list->add(1);
    list->add(2);
    list->add(9);

    EXPECT_EQ(1, list->begin());
}

TEST(containers, list_get_end)
{
    auto list = new list_type<int>{};
    list->add(1);
    list->add(2);
    list->add(9);

    EXPECT_EQ(9, list->end());
}

TEST(containers, list_destroy)
{
    auto list = new list_type<int>{};
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
