#include "containers.h"

#include "gtest/gtest.h"

template<typename T>
using queue_type = wingmann::algorithms::containers::queue<T>;

TEST(containers, queue_empty)
{
    queue_type<int> queue;
    EXPECT_TRUE(queue.is_empty());
}

TEST(containers, queue_enqueue)
{
    queue_type<int> queue;
    queue.enqueue(5);
    queue.enqueue(174);
    queue.enqueue(69);
    queue.enqueue(11);
    queue.enqueue(25);
    queue.enqueue(30);
    queue.enqueue(27);

    EXPECT_EQ(7, queue.size());
}

TEST(containers, queue_dequeue)
{
    queue_type<int> queue;
    queue.enqueue(5);
    queue.enqueue(174);
    queue.enqueue(69);
    queue.enqueue(11);
    queue.enqueue(25);
    queue.enqueue(30);
    queue.enqueue(27);

    EXPECT_EQ(5, queue.dequeue());
    EXPECT_EQ(174, queue.dequeue());
    EXPECT_EQ(69, queue.dequeue());
    EXPECT_EQ(11, queue.dequeue());

    EXPECT_EQ(3, queue.size());
}

TEST(containers, queue_front)
{
    queue_type<int> queue;
    queue.enqueue(5);
    queue.enqueue(174);
    queue.enqueue(69);
    queue.enqueue(11);

    EXPECT_EQ(4, queue.size());
    EXPECT_EQ(5, queue.front());
    EXPECT_EQ(4, queue.size());
}
