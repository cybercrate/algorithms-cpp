#ifndef WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H
#define WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H

#include <cstddef>
#include <memory>

namespace wingmann::algorithms::containers {

template<typename T>
class Queue {
    template<typename U>
    struct Node {
        U data;
        Node<U>* next;
    };

    Node<int>* front_;
    Node<T>* rear_;
    std::size_t size_;

public:
    Queue();
    virtual ~Queue() = default;

public:
    void enqueue(T item);
    T dequeue();
    T front();
    bool is_empty();
    std::size_t size();
    void clear();
};

template<typename T>
Queue<T>::Queue()
{
    front_ = nullptr;
    rear_ = nullptr;
    size_ = 0;
}

template<typename T>
void Queue<T>::enqueue(T item)
{
    auto new_node = new Node<T>;
    new_node->data = item;
    new_node->next = nullptr;

    if (is_empty()) {
        front_ = new_node;
        rear_ = new_node;
    }
    else {
        rear_->next = new_node;
        rear_ = rear_->next;
    }
    size_++;
}

template<typename T>
T Queue<T>::dequeue()
{
    if (is_empty()) return {};

    T result = front_->data;
    auto temp = front_;
    front_ = front_->next;
    delete temp;
    size_--;
    return result;
}

template<typename T>
T Queue<T>::front()
{
    return is_empty() ? T{} : front_->data;
}

template<typename T>
bool Queue<T>::is_empty()
{
    return front_ == nullptr;
}

template<typename T>
std::size_t Queue<T>::size()
{
    return size_;
}

template<typename T>
void Queue<T>::clear()
{
    front_ = nullptr;
}

} // namespace wingmann::algorithms::containers

#endif // WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H
