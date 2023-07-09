#include <trees_and_graphs/trees_and_graphs.h>
#include <queue>
#include <unordered_set>

namespace trees_and_graphs
{

bool routeBetweenNodes(Node<int>::Ptr nodeA, Node<int>::Ptr nodeB)
{
    // Trivial case
    if (nodeA == nodeB) { return true; }

    // Search queues
    std::queue<Node<int>::WeakPtr> queueA;
    std::queue<Node<int>::WeakPtr> queueB;

    // Track nodes that have been explored
    std::unordered_set<Node<int>::Ptr> visited;

    queueA.push(nodeA);
    visited.insert(nodeA);
    queueB.push(nodeB);
    visited.insert(nodeB);

    auto bfsStep = [&visited](std::queue<Node<int>::WeakPtr>& queue, Node<int>::Ptr find_node) {
        if (!queue.empty()) {
            auto visit = queue.front().lock();
            queue.pop();

            // Add children to search queue if unvisited
            for (const auto& node_ptr : visit->children) {
                if (visited.find(node_ptr.lock()) == visited.end()) {
                    queue.push(node_ptr);
                    visited.insert(node_ptr.lock());
                } else if (node_ptr.lock() == find_node) {
                    return true;
                } 
            }
        }

        return false;
    };

    while (!queueA.empty() || !queueB.empty()) {
        // Bi-directional bfs
        if (bfsStep(queueA, nodeB)) { return true; }
        if (bfsStep(queueB, nodeA)) { return true; }
    }

    return false;
}

} // namespace trees_and_graphs