#include <linked_lists/linked_list.h>
#include <linked_lists/linked_lists.h>

LinkedList<int> sumLists(const LinkedList<int>& list1, const LinkedList<int>& list2)
{
    int remainder = 0;
    int sum = 0;

    int sum1 = 0;
    int sum2 = 0;

    auto it1 = list1.head;
    auto it2 = list2.head;

    LinkedList<int> sum_list;

    while (it1 || it2) {

        if (it1) {
            sum1 = it1->data;
            it1 = it1->next;
        } else {
            sum1 = 0;
        }

        if (it2) {
            sum2 = it2->data;
            it2 = it2->next;
        } else {
            sum2 = 0;
        }

        sum = sum1 + sum2 + remainder;
        remainder = sum / 10;

        sum_list.append(sum % 10);
    }

    if (remainder) {
        sum_list.append(remainder);
    }

    return sum_list;
}

LinkedList<int> sumListsForward(const LinkedList<int>& list1, const LinkedList<int>& list2)
{
    auto list_sum = [](Node<int>::Ptr head, int& sum) {
        while (head) {
            sum = sum * 10 + head->data;
            head = head->next;
        }
    };

    int sum1 = 0;
    list_sum(list1.head, sum1);

    int sum2 = 0;
    list_sum(list2.head, sum2);

    auto sum = sum1 + sum2;

    LinkedList<int> sum_list;
    auto head = std::make_shared<Node<int>>(0);
    head->data = sum % 10;

    while (sum / 10) {
        sum /= 10;
        Node<int>::Ptr node = std::make_shared<Node<int>>(0);
        node->next = head;
        head = node;
        head->data = sum % 10;
    }

    sum_list.head = head;

    return sum_list;
}