#include <linked_lists/linked_list.h>
#include <linked_lists/linked_lists.h>
#include <stdint.h>

bool palindromeHelper(bool odd, int mid, int depth, Node<char>::Ptr& node)
{
    if (depth == mid) {
        if (odd) {
            node = node->next;
        }
        return true;
    } else {
        auto data = node->data;
        node = node->next;
        if (palindromeHelper(odd, mid, ++depth, node)) {
            auto new_data = node->data;
            node = node->next;
            return data == new_data;
        }
    }

    return false;
}

bool palindrome(const LinkedList<char>& list)
{
    auto it = list.head;

    // List is empty
    if (!it)
        return false;

    // List has only one character
    if (!it->next)
        return true;

    // Get the length of the list
    int len = 0;
    while (it) {
        it = it->next;
        len++;
    }

    int mid = len / 2;
    int depth = 0;
    auto node = list.head;
    auto odd = len % 2 != 0;

    return palindromeHelper(odd, mid, depth, node);
}