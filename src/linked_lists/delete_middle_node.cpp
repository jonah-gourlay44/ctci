#include <utils/linked_list.h>
#include <linked_lists.h>

void deleteMiddleNode(Node<int>::Ptr& node)
{
    if (node == nullptr)
        return;

    auto a = node;
    node = a->next;

    a.reset();
}