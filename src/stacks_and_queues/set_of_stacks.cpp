#include <stacks_and_queues/set_of_stacks.h>
#include <stdexcept>

namespace stacks_and_queues
{

SetOfStacks::SetOfStacks(int threshold)
    : threshold_(threshold)
{}

bool SetOfStacks::isEmpty()
{
    // Empty if no stacks in the set
    return set_.empty();
}

void SetOfStacks::push(int value)
{
    int last = set_.size() - 1;
    // If empty or most recent stack is full, add a new stack
    if (isEmpty() || set_[last].size() == threshold_) {
        set_.push_back(std::stack<int>());
        last++;
    }

    // Add value to last stack in the set
    set_[last].push(value);
}

void SetOfStacks::pop()
{
    // Do nothing if the set is empty
    if (isEmpty()) {
        return;
    }

    int last = set_.size() - 1;

    set_[last].pop();
    // Remove last stack if it is empty
    if (set_[last].empty()) {
        set_.erase(set_.begin() + last);
    }
}

int SetOfStacks::peek()
{
    // Can't return anything if the set is empty
    if (isEmpty()) {
        throw std::runtime_error("The set is empty");
    }

    // Return value at the top of most recent stack
    return set_[set_.size() - 1].top();
}

void SetOfStacks::popAt(int index)
{
    if (index >= set_.size()) {
        throw std::runtime_error("The given index is out of range");
    }

    set_[index].pop();

    // Remove the stack from the set if it is now empty
    if (set_[index].empty()) {
        set_.erase(set_.begin() + index);
    }
}

} // namespace stacks_and_queues