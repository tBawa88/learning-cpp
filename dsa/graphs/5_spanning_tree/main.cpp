#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "graph.h"
#include "newGraph.cpp"
#include "prioQueue.cpp"
using namespace std;

Graph<nodeT, edgeT>* Kruskals_MST(Graph<nodeT, edgeT>* g);
void PrintSpanningTree(Graph<nodeT, edgeT>* g);
/* Main function */
int main() {
    // Changed it to create an un-directed graph
    Graph<nodeT, edgeT>* g = CreateNewGraph<nodeT, edgeT>();
    Graph<nodeT, edgeT>* msTree = Kruskals_MST(g);

    PrintSpanningTree(msTree);

    delete g;
    delete msTree;
    return 0;
}

/**
 * Function : Kruskals_MST
 * Usage : Kruskals_MST(g)
 * -----------------------
 * Takes in a pointer to a graph and makes a Minimum spanning Tree out of it
 * (The tree with the smallest total edge cost)
 */
Graph<nodeT, edgeT>* Kruskals_MST(Graph<nodeT, edgeT>* g) {
    PrioQueue queue;
    Graph<nodeT, edgeT>* newGraph = new Graph<nodeT, edgeT>{};

    /**Initialzing the prio queue, and copy nodes in the newGraph*/
    for (edgeT* edge : g->getEdgeSet()) {
        newGraph->addNode(edge->start->name);
        newGraph->addNode(edge->finish->name);

        // Need to make a brand new edge otherwise it will contain old pointers to nodes which are connected
        edgeT* e = new edgeT{};
        e->start = newGraph->getNode(edge->start->name);
        e->finish = newGraph->getNode(edge->finish->name);
        queue.enqueue(e, edge->cost);
    }

    /*Start processing edges, in order of lesser cost first*/
    while (!queue.empty()) {
        /*Extract the edge with lowest cost*/
        edgeT* edge = queue.dequeue();
        nodeT* v1 = edge->start;
        nodeT* v2 = edge->finish;

        if (!newGraph->pathExists(v1, v2)) {
            newGraph->addEdge(v1, v2, edge->cost);
            newGraph->addEdge(v2, v1, edge->cost);
        }
    }
    return newGraph;
}

void PrintSpanningTree(Graph<nodeT, edgeT>* g) {
    set<nodeT*> visited;
    queue<nodeT*> queue;
    queue.push(*(g->getNodeSet().begin()));

    while (!queue.empty()) {
        nodeT* vert = queue.front();
        queue.pop();

        if (!visited.contains(vert)) {
            cout << vert->name;
            visited.insert(vert);

            for (edgeT* edge : vert->edges) {
                nodeT* n = edge->finish;
                if (!visited.contains(n)) {
                    cout << " ->" << n->name;
                    queue.push(n);
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}
