#pragma once
#include <exception>
#include <cstring>

namespace stacks_and_queues
{

/**
 * @brief Class representing three stacks
 * @tparam T The datatype contained by each stack
 * @details Implemented using an array for storage
 */
template <typename T>
class ThreeStack
{
public:
    /**
     * @brief Constructor
     */
    ThreeStack();

    /**
     * @brief Destructor
     */
    ~ThreeStack();

    /**
     * @brief Remove the top item from a stack
     * @param index The index of the stack to pop, can be 0, 1, or 2
     * @throws std::runtime_error If index is not 0, 1, or 2
     */
    void pop(int index);

    /**
     * @brief Add an item to the top of a stack
     * @param item The item to push onto the stack
     * @param index The index of the stack to push to, can be 0, 1, or 2
     * @throws std::runtime_error If index is not 0, 1, or 2
     */
    void push(const T& item, int index);

    /**
     * @brief Get the item at the top of a stack
     * @param index The index of the stack to push to, can be 0, 1, or 2
     * @return T The item at the top of the stack
     * @throws std::runtime_error If index is not 0, 1, or 2
     * @throws std::runtime_error If the stack is empty
     */
    T peek(int index);

    /**
     * @brief Check if a stack is empty
     * @param index The index of the stack to check, can be 0, 1, or 2
     * @return bool True iff the stack is empty
     * @throws std::runtime_error If index is not 0, 1, or 2
     */
    bool isEmpty(int index);

private:

    T* arr_;
    int top_indices_[3] = {-3,-2,-1}; // Initialize all three stacks to be empty
    int size_ = 3;
};

template <typename T>
ThreeStack<T>::ThreeStack()
    : arr_(new T[size_]) // Initialize each stack to have a size of 1
{}

template <typename T>
ThreeStack<T>::~ThreeStack()
{
    delete[] arr_;
}

template <typename T>
void ThreeStack<T>::pop(int index)
{
    if (index > 2 || index < 0) {
        throw std::runtime_error("Index invalid: valid options are 0, 1, 2.");
    }

    if (top_indices_[index] < 0) {
        return;
    }

    top_indices_[index] -= 3;
}

template <typename T>
void ThreeStack<T>::push(const T& item, int index)
{
    if (index > 2 || index < 0) {
        throw std::runtime_error("Index invalid: valid options are 0, 1, 2.");
    }

    // Double the array's capacity if the top index is out of bounds
    top_indices_[index] += 3;
    if (top_indices_[index] >= size_) {
        T* arr = new T[size_ * 2];
        memcpy(arr, arr_, size_ * sizeof(T));

        delete[] arr_;
        arr_ = arr;
        size_ *= 2;
    }

    arr_[top_indices_[index]] = item;
}

template <typename T>
T ThreeStack<T>::peek(int index)
{
    if (index > 2 || index < 0) {
        throw std::runtime_error("Index invalid: valid options are 0, 1, 2.");
    }

    if (top_indices_[index] < 0) {
        throw std::runtime_error("The stack is empty.");
    }

    return arr_[top_indices_[index]];
}

template <typename T>
bool ThreeStack<T>::isEmpty(int index)
{
    if (index > 2 || index < 0) {
        throw std::runtime_error("Index invalid: valid options are 0, 1, 2.");
    }

    return top_indices_[index] < 0;
}

} // namespace stacks_and_queues