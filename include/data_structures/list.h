#ifndef WINGALGO_DATA_STRUCTURES_LIST_H
#define WINGALGO_DATA_STRUCTURES_LIST_H

#include <vector>

namespace wing::algo {

template<typename T>
class list {
    struct node {
        T data;
        node* link;
    };

public:
    using size_type = std::size_t;
    using node_type = node;

private:
    node* first_;
    node* last_;
    size_type size_;

public:
    list();
    explicit list(node* start);
    ~list();

public:
    void destroy();
    bool remove(size_type position);

    void add(node* next);
    void add(T next_data);

    T& get(size_type position);
    bool set(size_type position, T new_data);

    size_type size();
    bool isEmpty();

    T& begin();
    T& end();

    void sort(bool ascending);
    void swap(node* i, node* j);
};

template<typename T>
list<T>::list() {
    first_ = nullptr;
    last_ = nullptr;
    size_ = 0;
}

template<typename T>
list<T>::list(node* start)
{
    if (start->link != nullptr) {
        auto current = first_ = start;

        for (size_type count = 0; current != nullptr; current = current->link) {
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
list<T>::~list()
{
    destroy();
}

template<typename T>
void list<T>::destroy()
{
    node* current;

    while (first_ != nullptr) {
        current = first_;
        first_ = first_->link;
        delete current;
    }
    last_ = nullptr;
    size_ = 0;
}

template<typename T>
bool list<T>::remove(size_type position)
{
    if (position <= (size_ - 1)) {
        auto current{first_};

        for (size_type i = 0; current != nullptr; current = current->link, i++) {
            if (i == (position - 1)) {
                auto temp = current->link;
                current->link = current->link->link;
                delete temp;
                size_--;
                return true;
            }
        }
    }
    return false;
}

template< typename T >
void list<T>::add(node* next)
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
void list<T>::add(T next_data)
{
    auto next = new node;
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
T& list<T>::get(size_type position)
{
    if (position <= (size_ - 1)) {
        auto current{first_};

        for (size_type i = 0; current; current = current->link, i++)
            if (i == position)
                return current->data;
    }
}

template<typename T>
bool list<T>::set(size_type position, T new_data)
{
    if (position <= (size_ - 1)) {
        auto current{first_};

        for (size_type i = 0; current != nullptr; current = current->link, i++) {
            if (i == position) {
                current->data = new_data;
                return true;
            }
        }
    }
    return false;
}

template<typename T>
typename list<T>::size_type list<T>::size()
{
    return size_;
}

template<typename T>
bool list<T>::isEmpty()
{
    return (first_ == nullptr);
}

template<typename T>
T& list<T>::begin()
{
    if (!isEmpty()) return first_->data;
}

template<typename T>
T& list<T>::end()
{
    if (!isEmpty()) return last_->data;
}

template<typename T>
void list<T>::sort(bool ascending)
{
    if (isEmpty()) return;

    node* i;
    node* j;

    auto sorter = (ascending)
        ? [this](auto a, auto b) { if (b->data < a->data) swap(a, b); }
        : [this](auto a, auto b) { if (b->data > a->data) swap(a, b); };

    for (i = first_; i != nullptr; i = i->link)
        for (j = i->link;j != nullptr; j = j->link)
            sorter(i, j);
}

template<typename T>
void list<T>::swap(node* i, node* j)
{
    T temp_data = i->data;
    i->data = j->data;
    j->data = temp_data;
}

} // namespace wing::algo

#endif // WINGALGO_DATA_STRUCTURES_LIST_H
