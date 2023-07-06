#include "linked_lists/linked_list.h"
#include "linked_lists/linked_lists.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace linked_lists;

TEST(LinkedLists, linked_list)
{
    LinkedList<int> list;

    list.append(3);
    list.append(5);
    list.append(7);

    auto n = list.head;
    ASSERT_EQ(n->data, 3);
    n = n->next;
    ASSERT_EQ(n->data, 5);
    n = n->next;
    ASSERT_EQ(n->data, 7);

    n = n->prev;
    list.remove(n);
    ASSERT_EQ(n, nullptr);
    n = list.head;
    ASSERT_EQ(n->data, 3);
    n = n->next;
    ASSERT_EQ(n->data, 7);

    LinkedList<int> list2(3, 4, 5, 6);

    n = list2.head;
    ASSERT_EQ(n->data, 3);
    n = n->next->next->next;
    ASSERT_EQ(n->data, 6);
    n = n->next;
    ASSERT_EQ(n, nullptr);
}

TEST(LinkedLists, remove_dups)
{
    LinkedList<int> list(4,4,5,6,5,4);

    removeDups(list);

    auto n = list.head;
    ASSERT_EQ(n->data, 4);
    n = n->next;
    ASSERT_EQ(n->data, 5);
    n = n->next;
    ASSERT_EQ(n->data, 6);
}

TEST(LinkedLists, return_kth_to_last)
{
    LinkedList<int> list(1,2,4,6);

    ASSERT_EQ(returnKthToLast(list, 2)->data, 4);
    ASSERT_EQ(returnKthToLast(list, 1)->data, 6);
    ASSERT_EQ(returnKthToLast(list, 3)->data, 2);
    ASSERT_EQ(returnKthToLast(list, 4)->data, 1);
    ASSERT_EQ(returnKthToLast(list, 5), nullptr);
}

TEST(LinkedLists, delete_middle_node)
{
    LinkedList<int> list(1,2,3);

    deleteMiddleNode(list.head->next);

    ASSERT_EQ(list.head->next->data, 3);
}

TEST(LinkedLists, partition)
{
    LinkedList<int> list(3,5,8,5,10,2,1);

    partition(list, 5);

    ASSERT_EQ(list.toVector(), std::vector<int>({3,2,1,5,10,5,8}));

    LinkedList<int> list2(1,6,10,8,9,6,1);

    partition(list2, 5);

    ASSERT_EQ(list2.toVector(), std::vector<int>({1,1,10,8,9,6,6}));
}

TEST(LinkedLists, sum_lists)
{
    LinkedList<int> list1(7,1,6);
    LinkedList<int> list2(5,9,2);

    ASSERT_EQ(sumLists(list1, list2).toVector(), std::vector<int>({2,1,9}));

    LinkedList<int> list3(4,3);
    LinkedList<int> list4(5,7,9,9);

    ASSERT_EQ(sumLists(list3, list4).toVector(), std::vector<int>({9,0,0,0,1}));

    LinkedList<int> list5(5,6);
    LinkedList<int> list6(7,8);

    ASSERT_EQ(sumListsForward(list5, list6).toVector(), std::vector<int>({1,3,4}));

    LinkedList<int> list7(9,7,5,2);
    LinkedList<int> list8(3,2,1);

    ASSERT_EQ(sumListsForward(list7, list8).toVector(), std::vector<int>({1,0,0,7,3}));
}

TEST(LinkedLists, palindrome)
{
    LinkedList<char> list1 ('a', 'b', 'c', 'b', 'a');

    ASSERT_TRUE(palindrome(list1));

    list1.append('a');

    ASSERT_FALSE(palindrome(list1));

    LinkedList<char> list2 ('a', 'b', 'b', 'a');

    ASSERT_TRUE(palindrome(list2));

    list2.append('c');
    list2.append('c');

    ASSERT_FALSE(palindrome(list2));

    list2.clear();

    ASSERT_FALSE(palindrome(list2));

    list2.append('a');

    ASSERT_TRUE(palindrome(list2));
}

TEST(LinkedLists, intersection)
{
    LinkedList<int> list1(2,3,1,4,5);
    LinkedList<int> list2;

    list2.head = list1.head->next->next;

    ASSERT_EQ(intersection(list1, list2), list1.head->next->next);

    list2 = LinkedList<int>(2,3,1,4,5);

    ASSERT_EQ(intersection(list1, list2), nullptr);
}

TEST(LinkedLists, loop_detection)
{
    LinkedList<int> list(3,4,1,5,2,6);

    ASSERT_EQ(loopDetection(list), nullptr);

    auto node = list.head;
    while (node->next) {
        node = node->next;
    }

    node->next = list.head->next->next;

    ASSERT_EQ(loopDetection(list), list.head->next->next);
}