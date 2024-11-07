/**
 * File : graph.h
 * -------------
 * This file defines an interface for a simple implementation of a graph data structure.
 * It uses a node structure and an edge structure to represent vertices and edges.
 *
 * It provides no class methods, the client must implement their own methods to build a graph data structure
 * (look at ariline.cpp to see how a graph is being built)
 */

#ifndef _graph_h
#define _graph_h

#include <map>
#include <set>
#include <string>

struct node; /*Forward refrence for the compiler to recognise them*/
struct edge;

/**
 * Type : graph
 * -------------
 * This type represents a graph and consists of two sets. A set of all the nodes, and a set of all the edges in the graph
 * Also it stores a map which associates a name with a specific node
 */
struct graph {
    std::set<node*> nodes;
    std::set<edge*> edges;
    std::map<std::string, node*> nodeMap;
};
/**
 * Type : node
 * ------------
 * This type represents a single node. Each node has a name, and a set of all the outgoing edges from this node.
 */
struct node {
    std::string name;
    std::set<edge*> edges;
};
/**
 * Type : edge
 * ------------
 * This type represent an edge between 2 nodes. It stores the starting node and the finishing node
 * I stores a numeric value which tells the cost of traversing from start to finish node
 */
struct edge {
    node* start;
    node* finish;
    double cost;
};

#endif
