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

vector<nodeT*> FindShortestPath(nodeT* current, nodeT* target);
double TotalPathCost(vector<edgeT*>& path);
void PrintPath(vector<edgeT*>& path);
void PrintPath(vector<nodeT*>& path);
vector<nodeT*> Dijkstra_2(nodeT* start, nodeT* finish);

/* Main function */
int main() {
    Graph<nodeT, edgeT>* g = CreateNewGraph<nodeT, edgeT>();

    // auto path = FindShortestPath(g->getNode("a"), g->getNode("c"));
    auto path = Dijkstra_2(g->getNode("a"), g->getNode("h"));
    PrintPath(path);
    // PrintGraph(g);

    delete g;
    return 0;
}

vector<nodeT*> FindShortestPath(nodeT* start, nodeT* target) {
    if (start == nullptr || target == nullptr)
        return {};
    map<nodeT*, double> costToNode;
    set<nodeT*> visited;
    PrioQueue pqueue;
    bool pathFound = false;
    // instead of setting each node's cost to Infinity, let's treat the node not being in the map as infinity
    costToNode[start] = 0;
    pqueue.enqueue(start, 0);

    while (!pqueue.empty()) {
        // extract node with minimum cost from queue
        nodeT* vert = pqueue.dequeue();
        visited.insert(vert);
        if (vert == target) {
            pathFound = true;
        }

        // visit each unvisited neighbor
        for (edgeT* edge : vert->edges) {
            if (!visited.contains(edge->finish)) {
                nodeT* neighbor = edge->finish;
                double newCost = costToNode[vert] + edge->cost;

                if (!costToNode.contains(neighbor) || newCost < costToNode[neighbor]) {
                    // Do 3 things : update cost in map, update cost in prio queue, set the previous field of this neigbor to current vert
                    costToNode[neighbor] = newCost;
                    pqueue.updatePriority(neighbor, newCost);
                    neighbor->previous = vert;
                }
            }
        }
    }

    vector<nodeT*> path{};
    if (!pathFound)
        return path;
    // Build the path vector using previous fields from the target to start
    while (target != start) {
        path.push_back(target);
        target = target->previous;
    }
    path.push_back(target);
    return path;
}

/**
 * Function : PrintPath(vector<nodeT*>path)
 * ------------------------------------------
 * Prints the given path in reverse
 *
 *
 */
void PrintPath(vector<nodeT*>& path) {
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i]->name;
        if (i != 0)
            cout << "-> ";
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

// Literally just a BFS which uses a prio queue to make them most optimla choice at each node
vector<nodeT*> Dijkstra_2(nodeT* start, nodeT* finish) {
    if (start == nullptr || finish == nullptr)
        return {};
    PrioQueue pqueue;
    set<nodeT*> visited;
    map<nodeT*, double> costToNode;
    bool pathFound = false;
    costToNode[start] = 0;
    pqueue.enqueue(start, 0);

    while (!pqueue.empty()) {
        nodeT* vert = pqueue.dequeue();
        visited.insert(vert);

        if (vert == finish) {
            pathFound = true;
            break;
        }

        // BFS : add all unvisited neighbors into the queue
        for (edgeT* edge : vert->edges) {
            nodeT* neighbor = edge->finish;
            if (!visited.contains(neighbor)) {
                double newCost = costToNode[vert] + edge->cost;
                if (!costToNode.contains(neighbor) || newCost < costToNode[neighbor]) {
                    costToNode[neighbor] = newCost;
                    pqueue.updatePriority(neighbor, newCost);
                    neighbor->previous = vert;
                }
            }
        }
    }

    if (!pathFound) return vector<nodeT*>{};

    vector<nodeT*> path;
    while (finish != start) {
        path.push_back(finish);
        finish = finish->previous;
    }
    path.push_back(start);
    return path;
}
