#include <iostream>
#include <queue>
#include <set>

#include "airline.cpp"
#include "followers.cpp"
#include "graph.h"

using namespace std;

void DepthFirstSearch(node* v);
void DFS_Helper(node* v, set<node*>& visited);
void BreadthFirstSearch(node* v);
void VisitNode(node* v);
void ClearGraph(graph* g);

int main() {
    graph* g = CreateFollowerGraph();
    // Find the coolest user -> user who's users have the most users
    PrintUsersGraph(g);

    ClearGraph(g);
    return 0;
}

int main2() {
    graph* g = CreateAirlineGraph();
    // PrintAirlineGraph(g);

    DepthFirstSearch(g->nodeMap["New Delhi"]);
    BreadthFirstSearch(g->nodeMap["New Delhi"]);

    ClearGraph(g);
    return 0;
}

// Recursively explores a single path untill it's end
void DepthFirstSearch(node* v) {
    set<node*> visited;
    cout << "\nDepth First Search ==== \n";
    DFS_Helper(v, visited);
}
void DFS_Helper(node* v, set<node*>& visited) {
    if (visited.contains(v))
        return;

    VisitNode(v);
    visited.insert(v);
    for (edge* arc : v->edges) {
        DFS_Helper(arc->finish, visited);
    }
}

// Iteratively visits each node, then all of it's immidiate neighbors, and so onn
void BreadthFirstSearch(node* v) {
    set<node*> visited;
    queue<node*> pending;

    cout << "\nBreadth First Search ====\n";
    pending.push(v);
    while (!pending.empty()) {
        node* currNode = pending.front();
        pending.pop();
        if (!visited.contains(currNode)) {
            VisitNode(currNode);
            visited.insert(currNode);
            for (edge* arc : currNode->edges) {
                pending.push(arc->finish);
            }
        }
    }
}

void VisitNode(node* v) {
    cout << v->name << endl;
}

/** Frees up the memory and clears all the nodes and edges from the graph */
void ClearGraph(graph* g) {
    for (node* n : g->nodes)
        delete n;
    for (edge* e : g->edges)
        delete e;
    delete g;
}
