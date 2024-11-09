#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include "graph.h"
#include "newGraph.cpp"
using namespace std;

vector<nodeT*> DFS(nodeT* start, nodeT* finish);
void DFS(nodeT* start, nodeT* finish, set<nodeT*>& visited, vector<nodeT*>& finalPath, vector<nodeT*>& currentPath, bool& pathFound);
void BFS(nodeT* start, nodeT* finish);

void PrintPath_Nodes(vector<nodeT*>& path);

/* Main function */
int main() {
    Graph<nodeT, edgeT>* g = CreateNewGraph<nodeT, edgeT>();

    // auto path = DFS(g->getNode("a"), g->getNode("i"));
    // PrintPath_Nodes(path);
    BFS(g->getNode("a"), g->getNode("i"));
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
vector<nodeT*> DFS(nodeT* current, nodeT* target) {
    vector<nodeT*> finalPath{};
    vector<nodeT*> currentPath{};
    set<nodeT*> visited;
    bool pathFound = false;
    currentPath.push_back(current);
    DFS(current, target, visited, finalPath, currentPath, pathFound);
    return finalPath;
}
void DFS(nodeT* current,
         nodeT* target,
         set<nodeT*>& visited,
         vector<nodeT*>& finalPath,
         vector<nodeT*>& currentPath,
         bool& pathFound) {
    if (!pathFound) {
        if (current == target) {
            finalPath = currentPath;  // The moment the target node is found, set the final path to the current path
            pathFound = true;
            return;
        }

        visited.insert(current);
        for (edgeT* edge : current->edges) {
            if (!visited.contains(edge->finish) && !pathFound) {
                currentPath.push_back(edge->finish);  // Choose the current node
                DFS(edge->finish, target, visited, finalPath, currentPath, pathFound);  // Explore the path
            }
        }
        // If control reaches here, that means path is not found via current node: remove it from the path
        currentPath.pop_back();
    }
}

void BFS(nodeT* current, nodeT* target) {
    queue<nodeT*> nodeQueue;
    queue<string> pathQueue;
    set<nodeT*> visited;
    nodeQueue.push(current);
    pathQueue.push(current->name);

    while (!nodeQueue.empty()) {
        current = nodeQueue.front();
        string pathStr = pathQueue.front();
        if (current == target) {
            cout << "Target node found" << endl;
            cout << pathStr << endl;
            break;
        }

        if (!visited.contains(current)) {
            visited.insert(current);
            for (edgeT* edge : current->edges) {
                // Create a new path from the current path for each neighbor, and push it to the queue
                pathQueue.push(pathStr + "->" + edge->finish->name);
                nodeQueue.push(edge->finish);
            }
        }
        nodeQueue.pop();
        pathQueue.pop();
    }
    // If control reaches here, there is no path found from current to finish node
}

void PrintPath_Nodes(vector<nodeT*>& path) {
    for (nodeT* node : path) {
        cout << node->name;
        if (node != path.back())
            cout << " -> ";
    }
    cout << endl;
}
