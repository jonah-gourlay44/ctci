#pragma once

namespace linked_lists
{

template <typename T>
class LinkedList;

template <typename T>
class Node;

/**
 * @brief Function to remove duplicates from an unsorted linked list
 * @param list The linked list to search
 */
void removeDups(LinkedList<int>& list);

/**
 * @brief Function to find the kth to last element of a singly linked list
 * @param list The linked list to search
 * @param k The distance from the end of the list
 * @return Node<int>* The node stored at the kth to last linked list element
 */
typename Node<int>::Ptr returnKthToLast(const LinkedList<int>& list, int k);

/**
 * @brief Function to delete a node from the middle of a linked list
 * @param node The node to delete
 */
void deleteMiddleNode(typename Node<int>::Ptr& node);

/**
 * @brief Function to partition a linked list
 * @param list The linked list to partition
 * @param x The value to partition around
 * @details All values less than x will appear in the left partition of the list
 */
void partition(LinkedList<int>& list, int x);

/**
 * @brief Function to sum numbers represented by linked lists
 * @param list1 The first list containing numerical digits
 * @param list2 The second list containing numerical digits
 * @return LinkedList<int> A list representing the sum of list1 and list2
 * @details Each node of the lists contains one digit of the number to be added, stored in reverse order
 */
LinkedList<int> sumLists(const LinkedList<int>& list1, const LinkedList<int>& list2);

/**
 * @brief Function to sum numbers represented by linked lists
 * @param list1 The first list containing numerical digits
 * @param list2 The second list containing numerical digits
 * @return LinkedList<int> A list representing the sum of list1 and list2
 * @details Each node of the lists contains one digit of a number to be added, stored in forward order
 */
LinkedList<int> sumListsForward(const LinkedList<int>& list1, const LinkedList<int>& list2);

/**
 * @brief Function to check if a linked list is a palindrome
 * @param list The list to check
 * @return bool true if list is a palindrome and false otherwise
 */
bool palindrome(const LinkedList<char>& list);

/**
 * @brief Function to determine if two linked lists intersect
 * @param list1 The first list
 * @param list2 The second list
 * @return Node<int>::Ptr The node where @list1 and @list2 intersect, nullptr if no intersection is found
 */
typename Node<int>::Ptr intersection(const LinkedList<int>& list1, const LinkedList<int>& list2);

/**
 * @brief Function to detect a loop in a linked list
 * @param list The list to check for loops
 * @return Node<int>::Ptr The node at the beginning of the loop, nullptr if no loop exists
 */
typename Node<int>::Ptr loopDetection(const LinkedList<int>& list);

} // namespace linked_lists