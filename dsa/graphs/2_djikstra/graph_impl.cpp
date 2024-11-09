/**
 * File : graph_impl.cpp
 * --------------------
 * This file contains all the implementations details fo the Graph class
 */

#include <set>
#include <string>

// #include "graph.h"

using namespace std;

#ifdef _graph_class_

template <typename NodeType, typename EdgeType>
Graph<NodeType, EdgeType>::Graph() {
}

template <typename Nodetype, typename Edgetype>
Graph<Nodetype, Edgetype>::~Graph() {
    clear();
}

template <typename NodeType, typename EdgeType>
void Graph<NodeType, EdgeType>::clear() {
    for (NodeType* node : nodes)
        delete node;
    for (EdgeType* edge : edges)
        delete edge;

    nodes.clear();
    edges.clear();
    nodeMap.clear();
}

template <typename NodeType, typename EdgeType>
NodeType* Graph<NodeType, EdgeType>::addNode(NodeType* node) {
    if (!nodeMap.contains(node->name)) {
        nodes.insert(node);
        nodeMap[node->name] = node;
        return node;
    }
    return nullptr;
}
template <typename NodeType, typename EdgeType>
NodeType* Graph<NodeType, EdgeType>::addNode(string name) {
    if (!nodeMap.contains(name)) {
        NodeType* node = new NodeType{};
        node->name = name;
        // node->edges = set<EdgeType*>(EdgeCompare<NodeType, EdgeType>);
        nodes.insert(node);
        nodeMap[name] = node;
        return node;
    }
    return nullptr;
}

template <typename NodeType, typename EdgeType>
EdgeType* Graph<NodeType, EdgeType>::addEdge(EdgeType* edge) {
    edge->start->edges.insert(edge);  // Insert this edge to the set of edges of it's starting node
    edges.insert(edge);
    return edge;
}

template <typename NodeType, typename EdgeType>
EdgeType* Graph<NodeType, EdgeType>::addEdge(NodeType* node1, NodeType* node2, double cost) {
    EdgeType* edge = new EdgeType{};
    edge->start = node1;
    edge->finish = node2;
    edge->cost = cost;
    node1->edges.insert(edge);
    edges.insert(edge);
    return edge;
}

template <typename NodeType, typename Edgetype>
Edgetype* Graph<NodeType, Edgetype>::addEdge(string name1, string name2, double cost) {
    return addEdge(getNode(name1), getNode(name2), cost);
}

template <typename NodeType, typename EdgeType>
bool Graph<NodeType, EdgeType>::isConnected(NodeType* node1, NodeType* node2) {
    // Check if any edge exists, in the set of edges for node1, whose finishing node is node2
    for (EdgeType* edge : node1->edges)
        if (edge->finish == node2)
            return true;
    return false;
}
template <typename NodeType, typename EdgeType>
bool Graph<NodeType, EdgeType>::isConnected(string name1, string name2) {
    return isConnected(getNode(name1), getNode(name2));
}

template <typename NodeType, typename EdgeType>
NodeType* Graph<NodeType, EdgeType>::getNode(string name) {
    if (nodeMap.contains(name))
        return nodeMap[name];
    return nullptr;
}

template <typename NodeType, typename EdgeType>
set<NodeType*>& Graph<NodeType, EdgeType>::getNodeSet() {
    return nodes;
}

template <typename NodeType, typename EdgeType>
set<EdgeType*>& Graph<NodeType, EdgeType>::getEdgeSet() {
    return edges;
}
template <typename NodeType, typename EdgeType>
set<EdgeType*>& Graph<NodeType, EdgeType>::getEdgeSet(NodeType* node) {
    return node->edges;
}

#endif
