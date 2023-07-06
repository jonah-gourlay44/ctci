#include <stacks_and_queues/stacks_and_queues.h>

namespace stacks_and_queues
{

void sort(std::stack<int>& stack)
{
    std::stack<int> peripheral;

    while (!stack.empty()) {
        auto next = stack.top();
        stack.pop();

        if (peripheral.empty()) {
            peripheral.push(next);
        } else {
            int i = 0;
            while (!peripheral.empty() && peripheral.top() > next) {
                stack.push(peripheral.top());
                peripheral.pop();
                i++;
            }

            peripheral.push(next);

            for (int j = 0; j < i; ++j) {
                peripheral.push(stack.top());
                stack.pop();
            }
        }
    }

    while (!peripheral.empty()) {
        stack.push(peripheral.top());
        peripheral.pop();
    }
}

} // namespace stacks_and_queues