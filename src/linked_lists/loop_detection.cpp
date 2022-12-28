#include <utils/linked_list.h>
#include <linked_lists.h>

Node<int>::Ptr loopDetection(const LinkedList<int>& list)
{
    // If list is empty, return early
    if (!list.head) {
        return nullptr;
    } 

    auto it_slow = list.head;
    auto it_fast = list.head;

    // Return early if there is only one node in the list
    if (!it_fast->next) {
        return nullptr;
    }

    // Iterate until the iterators collide or we reach the end of the list
    do {
        it_slow = it_slow->next;
        it_fast = it_fast->next->next;
    } while (it_fast && it_fast->next && it_slow != it_fast);

    // Return nullptr if there is no loop
    if (!it_fast || !it_fast->next) {
        return nullptr;
    }

    // Reset the slow pointer and move both one at a time until they collide again
    it_slow = list.head;
    while (it_slow != it_fast) {
        it_slow = it_slow->next;
        it_fast = it_fast->next;
    }

    // Both nodes are the same distance from the loop start, so return their collision point
    return it_slow;
}