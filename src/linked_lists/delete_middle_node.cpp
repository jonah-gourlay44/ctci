#include <linked_lists/linked_list.h>
#include <linked_lists/linked_lists.h>

namespace linked_lists
{

void deleteMiddleNode(Node<int>::Ptr& node)
{
    if (node == nullptr)
        return;

    auto a = node;
    node = a->next;

    a.reset();
}

} // namespace arrays_and_strings