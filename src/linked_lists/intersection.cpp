#include <linked_lists/linked_list.h>
#include <linked_lists/linked_lists.h>

Node<int>::Ptr intersection(const LinkedList<int>& list1, const LinkedList<int>& list2)
{
    // Get length of list
    auto length = [](auto&& list) {
        auto it = list.head;
        auto len = 0;
        while (it) {
            len++;
            it = it->next;
        }

        return len;
    };

    // Get length of list1
    auto len1 = length(list1);

    // Get length of list2
    auto len2 = length(list2);

    // Check for empty lists
    if (len1 == 0 || len2 == 0) {
        return nullptr;
    }

    // Get difference in length
    auto diff = len1 - len2;

    auto it1 = list1.head;
    auto it2 = list2.head;

    auto iterate = [](auto&& longer, auto&& shorter, int diff) -> Node<int>::Ptr {
        // Lists can't intersect in extra nodes
        for (int i = 0; i < abs(diff); i++) {
            longer = longer->next;
        }

        // Check for intersection
        while (longer && longer != shorter) {
            shorter = shorter->next;
            longer = longer->next;
        }

        if (shorter != longer) {
            return nullptr;
        }

        return shorter;

    };

    // list2 length is larger than list1 length
    if (diff < 0) { 
        return iterate(it2, it2, diff);
    } 
    
    // list1 length is larger than or equal to list2 length
    return iterate(it1, it2, diff);
}