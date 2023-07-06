#pragma once
#include <utility>
#include <vector>
#include <type_traits>
#include <memory>

namespace linked_lists
{

template <typename T>
struct Node {
    using Ptr = std::shared_ptr<Node<T>>;

    Node(const int data)
        : data(std::move(data))
    {}

    typename Node<T>::Ptr next = nullptr;
    typename Node<T>::Ptr prev = nullptr;

    T data;
};

template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    template <typename X, typename V> using is_valid_list_arg = std::is_same<std::remove_reference_t<V>, X>;

    template <typename... Args, typename = std::enable_if_t<std::conjunction_v<is_valid_list_arg<T, Args>...>>>
    LinkedList(Args&&... args) { initialize(std::forward<Args>(args)...); }

    void append(const T& val);

    void remove(typename Node<T>::Ptr& node);

    void clear();

    std::vector<T> toVector();

    typename Node<T>::Ptr head = nullptr;

private:
    template <typename Arg, typename... Args>
    void initialize(Arg&& arg, Args&&... args);

    void initialize();
};

template <typename T>
LinkedList<T>::LinkedList()
{}

template <typename T>
LinkedList<T>::~LinkedList()
{
}

template <typename T>
void LinkedList<T>::clear()
{
    if (head) {
        auto n = head;
        typename Node<T>::Ptr dealloc = nullptr;
        while (n->next != nullptr) {
            dealloc = n;
            n = n->next;
            dealloc.reset();
        }
        head = nullptr;
    }
}

template <typename T>
void LinkedList<T>::append(const T& val)
{
    if (!head) {
        head = std::make_shared<Node<T>>(val);
    } else {
        auto n = head;
        Node<T>* prev = nullptr;
        while (n->next != nullptr) {
            n = n->next;
        }
        n->next = std::make_shared<Node<T>>(val);
        n->next->prev = n;
    }
}

template <typename T>
void LinkedList<T>::remove(typename Node<T>::Ptr& node)
{
    if (!node) 
        return;

    if (node == head) {
        head = node->next;
        head->prev = nullptr;
        node.reset();
    } else {
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        node.reset();
    }

    node = nullptr;
}

template <typename T>
std::vector<T> LinkedList<T>::toVector()
{
    std::vector<T> vec;
    auto node = head;
    while (node) {
        vec.push_back(node->data);
        node = node->next;
    }

    return vec;
}

template <typename T>
template <typename Arg, typename... Args>
void LinkedList<T>::initialize(Arg&& arg, Args&&... args)
{
    append(arg);
    initialize(std::forward<Args>(args)...);
}

template <typename T>
void LinkedList<T>::initialize()
{

}

} // namepsace linked_lists