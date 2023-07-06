#pragma once
#include <stack>
#include <vector>

namespace stacks_and_queues
{
    
/**
 * @brief Class to store stacks in a set
 */
class SetOfStacks
{
public:

    /**
     * @brief Constructor
     * @param threshold Maximum size of an individual stack
     */
    SetOfStacks(int threshold);

    /**
     * @brief Destructor
     */
    ~SetOfStacks() = default;

    /**
     * @brief Push a value onto the set
     * @param value The value to push
     */
    void push(int value);

    /**
     * @brief Pop a value from the most recent stack in the set
     */
    void pop();

    /**
     * @brief Peek the current top value on the most resent stack in the set
     * @return int The head of the set
     */
    int peek();

    /**
     * @brief Check if the set is empty
     * @return bool True if the set is empty and false otherwise
     */
    bool isEmpty();

    /**
     * @brief Pop from the ith stack in the set
     * @param index The index of the stack to pop from
     */
    void popAt(int index);

private:
    std::vector<std::stack<int>> set_;
    int threshold_;
};

} // namespace stacks_and_queues