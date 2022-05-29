#ifndef WINGMANN_ALGORITHMS_CONTAINERS_LIST_H
#define WINGMANN_ALGORITHMS_CONTAINERS_LIST_H

#include <vector>

namespace wingmann::algorithms::containers {

template<typename T>
class List {
    struct Node {
        T data;
        Node* link;
    };

public:
    using ListNode = Node;

private:
    Node* first_{};
    Node* last_{};
    std::size_t size_{};

public:
    List() = default;
    explicit List(Node* start);
    ~List();

public:
    void destroy();
    bool remove(std::size_t position);

    void add(Node* next);
    void add(T next_data);

    T& get(std::size_t position) const;
    bool set(std::size_t position, T new_data);

    [[nodiscard]] std::size_t size() const;
    [[nodiscard]] bool is_empty() const;

    T& begin();
    T& end();

    void sort(bool ascending);
    void swap(Node* i, Node* j);
};

template<typename T>
List<T>::List(Node* start)
{
    if (start->link != nullptr) {
        auto current = first_ = start;

        for (std::size_t count = 0; current != nullptr; current = current->link) {
            count++;

            if (current->link == nullptr) {
                last_ = current;
                size_ = count;
            }
        }
    }
    else {
        first_ = start;
        last_ = start;
        size_ = 1;
    }
}

template<typename T>
List<T>::~List()
{
    destroy();
}

template<typename T>
void List<T>::destroy()
{
    Node* current;

    while (first_ != nullptr) {
        current = first_;
        first_ = first_->link;
        delete current;
    }
    last_ = nullptr;
    size_ = 0;
}

template<typename T>
bool List<T>::remove(std::size_t position)
{
    if (position <= (size_ - 1)) {
        auto current{first_};

        for (std::size_t i = 0; current != nullptr; current = current->link, i++) {
            if (i == (position - 1)) {
                auto temp = current->link;
                current->link = current->link->link;
                delete temp;
                size_--;
                return true;
            }
        }
    }
    return {};
}

template< typename T >
void List<T>::add(Node* next)
{
    if (!first_) {
        first_ = next;
        last_ = next;
        last_->link = nullptr;
        size_++;
    }
    else {
        last_->link = next;
        last_ = next;
        last_->link = nullptr;
        size_++;
    }
}

template<typename T>
void List<T>::add(T next_data)
{
    auto next = new Node;
    next->data = next_data;
    next->link = nullptr;

    if (!first_) {
        first_ = next;
        last_ = next;
        last_->link = nullptr;
        size_++;
    }
    else {
        last_->link = next;
        last_ = next;
        last_->link = nullptr;
        size_++;
    }
}

template<typename T>
T& List<T>::get(std::size_t position) const
{
    if (position <= (size_ - 1)) {
        auto current{first_};

        for (std::size_t i = 0; current; current = current->link, i++)
            if (i == position)
                return current->data;
    }
}

template<typename T>
bool List<T>::set(std::size_t position, T new_data)
{
    if (position <= (size_ - 1)) {
        auto current{first_};

        for (std::size_t i = 0; current != nullptr; current = current->link, i++) {
            if (i == position) {
                current->data = new_data;
                return true;
            }
        }
    }
    return {};
}

template<typename T>
std::size_t List<T>::size() const
{
    return size_;
}

template<typename T>
bool List<T>::is_empty() const
{
    return (first_ == nullptr);
}

template<typename T>
T& List<T>::begin()
{
    if (!is_empty()) return first_->data;
}

template<typename T>
T& List<T>::end()
{
    if (!is_empty()) return last_->data;
}

template<typename T>
void List<T>::sort(bool ascending)
{
    if (is_empty()) return;

    Node* i;
    Node* j;

    auto sorter = (ascending)
        ? [this](auto a, auto b) { if (b->data < a->data) swap(a, b); }
        : [this](auto a, auto b) { if (b->data > a->data) swap(a, b); };

    for (i = first_; i != nullptr; i = i->link)
        for (j = i->link;j != nullptr; j = j->link)
            sorter(i, j);
}

template<typename T>
void List<T>::swap(Node* i, Node* j)
{
    T temp_data = i->data;
    i->data = j->data;
    j->data = temp_data;
}

} // namespace wingmann::algorithms::containers

#endif // WINGMANN_ALGORITHMS_CONTAINERS_LIST_H
