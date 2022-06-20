#ifndef WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H
#define WINGMANN_ALGORITHMS_CONTAINERS_QUEUE_H

#include <optional>

namespace wingmann::algorithms::containers {

template<typename T>
class queue {
    struct node {
        T data;
        node* next;
    };

public:
    using node_type = node;

protected:
    std::size_t size_{};
    node* front_{};
    node* rear_{};

public:
    queue() = default;
    virtual ~queue() = default;

public:
    void enqueue(T item);
    std::optional<T> dequeue();
    std::optional<T> front();
    bool is_empty();
    std::size_t size();
    void clear();
};

template<typename T>
void queue<T>::enqueue(T item)
{
    auto new_node = new node{};
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
std::optional<T> queue<T>::dequeue()
{
    if (!is_empty()) {
        T result = front_->data;
        auto temp = front_;
        front_ = front_->next;
        delete temp;
        size_--;
        return result;
    }
    return std::nullopt;
}

template<typename T>
std::optional<T> queue<T>::front()
{
    if (!is_empty())
        return front_->data;

    return std::nullopt;
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
