#include <trees_and_graphs/trees_and_graphs.h>
#include <gtest/gtest.h>

using namespace trees_and_graphs;

TEST(TreesAndGraphs, test_route_between_nodes)
{
    Graph<int> graph;
    graph.nodes.push_back(Node<int>::create(5));
    graph.nodes.push_back(Node<int>::create(7));
    graph.nodes.push_back(Node<int>::create(2));
    graph.nodes.push_back(Node<int>::create(4));
    graph.nodes.push_back(Node<int>::create(11));
    graph.nodes.push_back(Node<int>::create(23));
    graph.nodes.push_back(Node<int>::create(1));

    // Sanity check
    ASSERT_FALSE(routeBetweenNodes(graph.nodes[0], graph.nodes[2]));
    ASSERT_TRUE(routeBetweenNodes(graph.nodes[0], graph.nodes[0]));
    
    graph.nodes[0]->children.push_back(graph.nodes[1]);
    graph.nodes[0]->children.push_back(graph.nodes[2]); 
    graph.nodes[0]->children.push_back(graph.nodes[6]);

    graph.nodes[1]->children.push_back(graph.nodes[4]);
    graph.nodes[1]->children.push_back(graph.nodes[5]);

    graph.nodes[2]->children.push_back(graph.nodes[6]);

    graph.nodes[4]->children.push_back(graph.nodes[3]);

    graph.nodes[6]->children.push_back(graph.nodes[4]);

    ASSERT_TRUE(routeBetweenNodes(graph.nodes[0], graph.nodes[3]));
    ASSERT_FALSE(routeBetweenNodes(graph.nodes[1], graph.nodes[6]));
    ASSERT_FALSE(routeBetweenNodes(graph.nodes[2], graph.nodes[5]));

    // Introduce cycle
    graph.nodes[3]->children.push_back(graph.nodes[0]);

    // All nodes should connect
    for (const auto& nodeA : graph.nodes) {
        for (const auto& nodeB : graph.nodes) {
            // Ignore self
            if (nodeA == nodeB) { continue; }

            ASSERT_TRUE(routeBetweenNodes(nodeA, nodeB)) << 
                "nodeA: " << nodeA->data << ", "
                "nodeB: " << nodeB->data;
        }
    }
}