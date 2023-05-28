#include <stacks_and_queues/my_queue.h>

void MyQueue::add(int item)
{
    push_stack.push(item);
}

void MyQueue::remove()
{
    pop_stack.pop();
}

int MyQueue::peek()
{
    if (pop_stack.empty()) {
        while (!push_stack.empty()) {
            pop_stack.push(push_stack.top());
            push_stack.pop();
        }
    }

    return pop_stack.top();
}

bool MyQueue::isEmpty()
{
    return pop_stack.empty() && push_stack.empty();
}