#include <stacks_and_queues/stacks_and_queues.h>
#include <stacks_and_queues/set_of_stacks.h>
#include <stacks_and_queues/my_queue.h>
#include <gtest/gtest.h>

TEST(StacksAndQueues, test_set_of_stacks)
{
    SetOfStacks stack_set(3);

    ASSERT_TRUE(stack_set.isEmpty());

    stack_set.push(3);
    stack_set.push(2);
    stack_set.push(10);
    stack_set.push(1);
    stack_set.push(4);
    stack_set.push(5);
    stack_set.push(19);

    ASSERT_EQ(stack_set.peek(), 19);
    ASSERT_FALSE(stack_set.isEmpty());

    stack_set.pop();

    ASSERT_EQ(stack_set.peek(), 5);
    ASSERT_FALSE(stack_set.isEmpty());

    stack_set.popAt(0);
    stack_set.popAt(0);
    stack_set.popAt(1);
    stack_set.popAt(0);

    ASSERT_EQ(stack_set.peek(), 4);
    ASSERT_FALSE(stack_set.isEmpty());

    stack_set.popAt(0);

    ASSERT_EQ(stack_set.peek(), 1);

    stack_set.pop();
    stack_set.pop();

    ASSERT_TRUE(stack_set.isEmpty());
}

TEST(StacksAndQueues, test_queue_via_stacks)
{
    MyQueue queue;

    ASSERT_TRUE(queue.isEmpty());

    queue.add(4);

    ASSERT_FALSE(queue.isEmpty());
    ASSERT_EQ(queue.peek(), 4);

    queue.remove();

    ASSERT_TRUE(queue.isEmpty());

    for (int i = 0; i < 30; i++) {
        queue.add(i);
    }

    ASSERT_EQ(queue.peek(), 0);

    queue.add(30);
    queue.remove();

    ASSERT_EQ(queue.peek(), 1);
}

TEST(StacksAndQueues, test_sort_stack)
{
    std::stack<int> my_stack;
    
    for (const auto& num : { 3, 4, 6, 4, 7, 8 }) {
        my_stack.push(num);
    }

    sort(my_stack);

    std::vector<int> order { 3, 4, 4, 6, 7, 8};
    for (const auto& num : order) {
        ASSERT_EQ(my_stack.top(), num);
        my_stack.pop();
    }
}