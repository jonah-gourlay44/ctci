#pragma once

#include <stack>

/**
 * @brief Queue implemented with two stacks
*/
class MyQueue
{
public:
    MyQueue() = default;

    ~MyQueue() = default;

    /**
     * @brief Add an item to the end of the queue
     * @param item An integer item to add
    */
    void add(int item);

    /**
     * @brief Remove an item from the front of the queue
    */
    void remove();

    /**
     * @brief Get the item at the front of the queu
     * @return The item at the front
    */
    int peek();

    /**
     * @brief Check if the queue is empty
     * @return True if the queu is empty and false otherwise
    */
    bool isEmpty();

private:
    std::stack<int> push_stack;
    std::stack<int> pop_stack;
};