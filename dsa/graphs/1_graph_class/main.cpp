#include <iostream>
#include <map>
#include <set>
#include <string>

#include "airline.cpp"
#include "graph.h"
using namespace std;

int main() {
    // Creating a graph using nodeT for a NodeType and edgeT for EdgeType
    Graph<nodeT, edgeT>* g = CreateAirlineGraph<nodeT, edgeT>();

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

    delete g;
    return 0;
}
