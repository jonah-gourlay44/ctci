#include "linked_lists/linked_list.h"
#include "linked_lists/linked_lists.h"

#include <unordered_set>
#include <unordered_map>

namespace linked_lists
{

void removeDups(LinkedList<int>& list)
{
    std::unordered_set<int> lookup;

    auto n = list.head;

    if (!n)
        return;

    Node<int>::Ptr dealloc = nullptr;
    while(n) {
        if (lookup.count(n->data) == 0) {
            lookup.insert(n->data);
            n = n->next;
        } else {
            dealloc = n;
            n = n->next;
            list.remove(dealloc);
        }
    }
}

} // namespace arrays_and_strings