#include <linked_lists/linked_list.h>
#include <linked_lists/linked_lists.h>

namespace linked_lists
{

void partition(LinkedList<int>& list, int x)
{
    // list is empty
    if (list.head == nullptr) {
        return;
    }

    // Find partition point
    auto p1 = list.head;
    auto p2 = p1;
    while (p1 && p1->data < x) {
        p1 = p1->next;
        p2 = p1;
    }

    if (!p1) {
        return;
    }

    while (p2->next) {
        p2 = p2->next;

        // Swap p1 and p2 data if p2 is on wrong side of partition
        if (p2->data < x) {
            auto data = p1->data;
            p1->data = p2->data;
            p2->data = data;

            p1 = p1->next;
        }
    }
}

} // namespace arrays_and_strings