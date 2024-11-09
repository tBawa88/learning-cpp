#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "graph.h"
#include "newGraph.cpp"
using namespace std;

vector<nodeT*> DFS(nodeT* start, nodeT* finish);
void DFS(nodeT* start, nodeT* finish, set<nodeT*>& visited, vector<nodeT*>& finalPath, vector<nodeT*>& currentPath, bool& pathFound);

void PrintPath_Nodes(vector<nodeT*>& path);

/* Main function */
int main() {
    Graph<nodeT, edgeT>* g = CreateNewGraph<nodeT, edgeT>();

    auto path = DFS(g->getNode("a"), g->getNode("i"));
    PrintPath_Nodes(path);
    // PrintGraph(g);
    delete g;
    return 0;
}

/**
 * Function : DFS
 * Usage : DFS(n1, n2);
 * ---------------------
 * Tries to find a path between node1 and node2 using Depth First Search
 * IF a path exists, it is guaranteed to be found (DFS explores every possible path untill the end)
 * If no path exists, it returns an empty vector
 */
vector<nodeT*> DFS(nodeT* start, nodeT* finish) {
    vector<nodeT*> finalPath{};
    vector<nodeT*> currentPath{};
    set<nodeT*> visited;
    bool pathFound = false;
    currentPath.push_back(start);
    DFS(start, finish, visited, finalPath, currentPath, pathFound);
    return finalPath;
}
void DFS(nodeT* start,
         nodeT* finish,
         set<nodeT*>& visited,
         vector<nodeT*>& finalPath,
         vector<nodeT*>& currentPath,
         bool& pathFound) {
    if (!pathFound) {
        if (start == finish) {
            finalPath = currentPath;  // The moment the target node is found, set the final path to the current path
            pathFound = true;
            return;
        }

        // Visit the node -> choose it's path
        visited.insert(start);
        for (edgeT* edge : start->edges) {
            // If the neirhbor has not been visited, Explore that path
            if (!visited.contains(edge->finish) && !pathFound) {
                currentPath.push_back(edge->finish);
                DFS(edge->finish, finish, visited, finalPath, currentPath, pathFound);
            }
        }
        // If control reaches here, that means path is not found via current node: remove it from the path
        currentPath.pop_back();
    }
}

void PrintPath_Nodes(vector<nodeT*>& path) {
    for (nodeT* node : path) {
        cout << node->name;
        if (node != path.back())
            cout << " -> ";
    }
    cout << endl;
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
