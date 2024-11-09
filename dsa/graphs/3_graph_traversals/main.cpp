#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "airline.cpp"
#include "graph.h"
using namespace std;

/* Main function */
int main() {
    Graph<nodeT, edgeT>* g = CreateAirlineGraph<nodeT, edgeT>();
    PrintAirlineGraph(g);

    delete g;
    return 0;
}

void PrintPath(vector<edgeT*>& path) {
    bool first = true;
    for (edgeT* edge : path) {
        if (first)
            cout << edge->start->name;
        cout << " -> " << edge->finish->name;
        first = false;
    }
    cout << endl;
}
