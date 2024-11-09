#include <iostream>
#include <map>
#include <set>
#include <string>

#include "airline.cpp"
#include "graph.h"
#include "prioQueue.cpp"
using namespace std;

vector<edgeT*> FindShortesPath(nodeT* current, nodeT* finish);
double TotalPathDistance(vector<edgeT*>& path);
void PrintPath(vector<edgeT*>& path);
int main() {
    Graph<nodeT, edgeT>* g = CreateAirlineGraph<nodeT, edgeT>();

    vector<edgeT*> shortestPath = FindShortesPath(g->getNode("San Francisco"), g->getNode("Boston"));
    PrintPath(shortestPath);

    delete g;
    return 0;
}

vector<edgeT*> FindShortesPath(nodeT* current, nodeT* finish) {
    vector<edgeT*> path{};
    PrioQueue queue;
    map<string, double> fixed;  // to keep track of fixed nodes(nodes that will appear in the shortest path)

    while (current != finish) {
        if (!fixed.contains(current->name)) {
            // cout << "\nFixing city " << current->name << " Total distance till now " << TotalPathDistance(path) << endl;
            fixed[current->name] = TotalPathDistance(path);

            // for each edge of this currentNode, check if they've been enqueued or not
            for (edgeT* edge : current->edges) {
                if (!fixed.contains(edge->finish->name)) {
                    vector<edgeT*> newpath = path;  // copy the path till now
                    newpath.push_back(edge);  // add this edge to the new path
                    // cout << "\nEnqueue path ->";
                    // PrintPath(newpath);
                    queue.enqueue(newpath, TotalPathDistance(newpath));  // enqueue this new path to the prio queue
                }
            }
        }
        // Now it's time to choose the shorted path from the queue
        // But if the queue itself is empty(meaning all the paths have been dequeue'd from it, and we're still not done looking)
        if (queue.empty()) return vector<edgeT*>{};
        path = queue.dequeue();  // extract the shortest path from the queue, and explore this path
        // cout << "\n Current Shortest path => ";
        // PrintPath(path);
        current = path[path.size() - 1]->finish;
    }
    return path;
}

double TotalPathDistance(vector<edgeT*>& path) {
    double distance = 0;
    for (edgeT* edge : path)
        distance += edge->cost;

    return distance;
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
