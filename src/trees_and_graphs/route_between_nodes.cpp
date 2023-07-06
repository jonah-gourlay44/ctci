#include <trees_and_graphs/trees_and_graphs.h>
#include <queue>

namespace trees_and_graphs
{

bool routeBetweenNodes(Node<int>::Ptr nodeA, Node<int>::Ptr nodeB)
{
    std::queue<Node<int>::WeakPtr> queueA;
    std::queue<Node<int>::WeakPtr> queueB;

    for (const auto& node_ptr : nodeA->children) {
        queueA.push(node_ptr);
    }

    for (const auto& node_ptr : nodeB->children) {
        queueB.push(node_ptr);
    }

    while (!queueA.empty() || !queueB.empty()) {
        if (!queueA.empty()) {
            if (queueA.front().lock() == nodeB) {
                return true;
            }
            for (const auto& node_ptr : queueA.front().lock()->children) {
                if (node_ptr.lock() != nodeA) {
                    queueA.push(node_ptr);
                }
            }
            queueA.pop();
        }

        if (!queueB.empty()) {
            if (queueB.front().lock() == nodeA) {
                return true;
            }
            for (const auto& node_ptr : queueB.front().lock()->children) {
                if (node_ptr.lock() != nodeB) {
                    queueB.push(node_ptr);
                }
            }
            queueB.pop();
        }  
    }

    return false;
}

} // namespace trees_and_graphs