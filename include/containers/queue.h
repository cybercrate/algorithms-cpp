#ifndef WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H
#define WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H

#include <cstddef>
#include <memory>

namespace wingmann::algorithms::containers {

template<typename T>
class queue {
    template<typename U>
    struct node {
        U data;
        node<U>* next;
    };

    node<int>* front_;
    node<T>* rear_;
    std::size_t size_;

public:
    queue();
    virtual ~queue() = default;

public:
    void enqueue(T item);
    T dequeue();
    T front();
    bool is_empty();
    std::size_t size();
    void clear();
};

template<typename T>
queue<T>::queue()
{
    front_ = nullptr;
    rear_ = nullptr;
    size_ = 0;
}

template<typename T>
void queue<T>::enqueue(T item)
{
    auto new_node = new node<T>;
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
T queue<T>::dequeue()
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
T queue<T>::front()
{
    return is_empty() ? T{} : front_->data;
}

template<typename T>
bool queue<T>::is_empty()
{
    return front_ == nullptr;
}

template<typename T>
std::size_t queue<T>::size()
{
    return size_;
}

template<typename T>
void queue<T>::clear()
{
    front_ = nullptr;
}

} // namespace wingmann::algorithms::containers

#endif // WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H
