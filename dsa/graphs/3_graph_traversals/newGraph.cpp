#include <iostream>
#include <map>
#include <set>
#include <string>

#include "graph.h"
using namespace std;

template <typename Nodetype, typename Edgetype>
Graph<Nodetype, Edgetype>* CreateNewGraph();

template <typename NodeType, typename EdgeType>
void AddEdge(Graph<NodeType, EdgeType>* g, string city1, string city2, double miles);

template <typename NodeType, typename EdgeType>
void AddNode(Graph<NodeType, EdgeType>* g, string name);

template <typename Nodetype, typename Edgetype>
Graph<Nodetype, Edgetype>* CreateNewGraph() {
    Graph<Nodetype, Edgetype>* g = new Graph<Nodetype, Edgetype>{};
    AddNode(g, "a");
    AddNode(g, "b");
    AddNode(g, "c");
    AddNode(g, "d");
    AddNode(g, "e");
    AddNode(g, "f");
    AddNode(g, "g");
    AddNode(g, "h");
    AddNode(g, "i");
    AddEdge(g, "a", "b", 0);
    AddEdge(g, "a", "d", 0);
    AddEdge(g, "a", "e", 0);
    AddEdge(g, "b", "e", 0);
    AddEdge(g, "c", "e", 0);
    AddEdge(g, "d", "g", 0);
    AddEdge(g, "d", "h", 0);
    AddEdge(g, "e", "f", 0);
    AddEdge(g, "f", "c", 0);
    AddEdge(g, "g", "h", 0);
    AddEdge(g, "h", "e", 0);
    AddEdge(g, "h", "f", 0);
    AddEdge(g, "h", "i", 0);
    AddEdge(g, "i", "c", 0);

    return g;
}
/**
 * Function : AddNode
 * Usage : AddNode(g, "city_name");
 * --------------------------------
 * It calls g->addNode() and adds a new node into the Graph with given name
 */
template <typename NodeType, typename EdgeType>
void AddNode(Graph<NodeType, EdgeType>* g, string name) {
    g->addNode(name);
}
/**
 * Function : AddEdge
 * Usage : AddEdge(g, "city1", "city2");
 * ------------------------------------
 * It calls g->addEdge(), and creates a bi-directional edge between city1 and city2
 */
template <typename NodeType, typename EdgeType>
void AddEdge(Graph<NodeType, EdgeType>* g, string city1, string city2, double miles) {
    g->addEdge(city1, city2, miles);
    // g->addEdge(city2, city1, miles);
}

template <typename NodeType, typename EdgeType>
void PrintGraph(Graph<NodeType, EdgeType>* g) {
    for (nodeT* node : g->getNodeSet()) {
        cout << node->name << " => ";
        bool commaa = false;
        for (edgeT* edge : g->getEdgeSet(node)) {
            if (commaa)
                cout << ", ";
            cout << edge->finish->name;
            commaa = true;
        }
        cout << endl;
    }
}