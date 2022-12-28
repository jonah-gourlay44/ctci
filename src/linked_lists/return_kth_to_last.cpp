#include "utils/linked_list.h"
#include "linked_lists.h"

Node<int>::Ptr returnKthToLast(const LinkedList<int>& list, int k)
{
    // First pointer
    auto head = list.head;
    int i = 0;

    // Second pointer
    auto p2 = list.head;
    bool is_p2_k_away = false;
    while (head->next != nullptr) {
        // Increment second pointer if first pointer is k nodes away
        if (is_p2_k_away) {
            p2 = p2->next;
        }

        // Check if first pointer is k nodes away
        if ((i + 1 == k) && !is_p2_k_away) {
            p2 = p2->next;
            is_p2_k_away = true;
        }

        head = head->next;
        i++;
    }

    if (i + 1 < k) {
        return nullptr;
    }

    return p2;
}