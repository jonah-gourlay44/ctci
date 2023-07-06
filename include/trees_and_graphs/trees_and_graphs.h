#pragma once
#include <trees_and_graphs/graph.h>

namespace trees_and_graphs
{

/**
 * @brief Determine if a route exists between two nodes in a directed graph
 * @param nodeA The first node
 * @param nodeB The second node
 * @return True if a route exists between nodeA and nodeB and False otherwise
*/
bool routeBetweenNodes(Node<int>::Ptr nodeA, Node<int>::Ptr nodeB);

} // namespace trees_and_graphs