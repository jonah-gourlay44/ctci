#pragma once

#include <vector>
#include <memory>

namespace trees_and_graphs
{

template <typename T>
struct Node {
    using Ptr = std::shared_ptr<Node<T>>;
    using WeakPtr = std::weak_ptr<Node<T>>;

    Node(T _data) 
        : data(std::move(_data))
    {}

    static Ptr create(T _data) { return std::make_shared<Node<T>>(std::move(_data)); }
    static Ptr create() { return std::make_shared<Node<T>>(); }

    T data;
    std::vector<Node<T>::WeakPtr> children;
};

template <typename T>
struct Graph {
    std::vector<typename Node<T>::Ptr> nodes;
};

} // namespace trees_and_graphs