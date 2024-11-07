#include <fstream>
#include <iostream>
#include <stdexcept>

#include "graph.h"

using namespace std;
void AddFollower(graph* g, string follower, string leader);
void AddUser(graph* g, string name);
void AddEdge(graph* g, node* user1, node* user2);

graph* CreateFollowerGraph() {
    ifstream file;
    file.open("friendlist");

    if (!file.is_open()) {
        throw runtime_error{"failed to open file"};
    }

    graph* g = new graph{};
    string name1, name2;
    while (file >> name1 >> name2) {
        AddUser(g, name1);
        AddUser(g, name2);
        AddFollower(g, name1, name2);
    }
    return g;
}

void AddUser(graph* g, string name) {
    node* user = new node{};
    user->name = name;
    g->nodes.insert(user);
    g->nodeMap[name] = user;
}

void AddFollower(graph* g, string follower, string leader) {
    node* f_node = g->nodeMap[follower];
    node* l_node = g->nodeMap[leader];
    AddEdge(g, f_node, l_node);
}

/* Adds a directed edge from user 1 to user 2*/
void AddEdge(graph* g, node* user1, node* user2) {
    edge* arc = new edge{};
    arc->start = user1;
    arc->finish = user2;
    user1->edges.insert(arc);
    g->edges.insert(arc);
}

void PrintUsersGraph(graph* g) {
    for (node* user : g->nodes) {
        cout << user->name << " -> ";
        bool commaNeeded = false;
        for (edge* follwer : user->edges) {
            if (commaNeeded)
                cout << ", ";
            cout << follwer->finish->name;
            commaNeeded = true;
        }
        cout << endl;
    }
}
