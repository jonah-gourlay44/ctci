#include <stacks_and_queues/stacks_and_queues.h>
#include <stacks_and_queues/set_of_stacks.h>
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