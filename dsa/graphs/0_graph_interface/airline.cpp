/**
 * File : airline.cpp
 * -----------------
 * This file contains implementation (methods) for building a graph for an imaginary ariline company.
 * Each node is a representation of a city.
 * Each edge connects two cities, signifying that there is a flight that connects them.
 */
#include <iostream>
#include <string>

#include "graph.h"

using namespace std;

void AddCity(graph* g, string name);
void AddFlight(graph* g, string c1, string c2, double miles);
void AddEdge(graph* g, node* c1, node* c2, double cost);

/**
 * Builder: graph
 * -------------
 * - Creates a pointer to a graph object.
 * - Adds nodes(cities) to it's set of nodes
 * - Adds edges(flights) to it's set of edges
 * - Returns the pointer.
 */
graph* CreateAirlineGraph() {
    graph* g = new graph;
    AddCity(g, "New Delhi");
    AddCity(g, "Kolkata");
    AddCity(g, "Punjab");
    AddCity(g, "Mumbai");
    AddCity(g, "Chandigarh");
    AddCity(g, "Kerela");
    AddCity(g, "Indore");
    AddCity(g, "Chennai");
    AddCity(g, "Bangalore");
    AddCity(g, "Trivandrum");
    AddFlight(g, "New Delhi", "Punjab", 599);
    AddFlight(g, "New Delhi", "Mumbai", 725);
    AddFlight(g, "New Delhi", "Indore", 756);
    AddFlight(g, "Kolkata", "Indore", 191);
    AddFlight(g, "Kolkata", "Trivandrum", 2489);
    AddFlight(g, "Punjab", "Chandigarh", 907);
    AddFlight(g, "Mumbai", "Chandigarh", 650);
    AddFlight(g, "Mumbai", "Kerela", 1240);
    AddFlight(g, "Mumbai", "Bangalore", 1468);
    AddFlight(g, "Chandigarh", "Bangalore", 954);
    AddFlight(g, "Chennai", "Trivandrum", 130);
    AddFlight(g, "Chennai", "Bangalore", 550);

    return g;
}

/* Creates a new node representing the city, adds it to the set of vertices of the graph */
void AddCity(graph* g, string name) {
    node* city = new node{};
    city->name = name;
    g->nodes.insert(city);
    g->nodeMap[name] = city;
}

/**
 * Adds an edge, representing a flight, in each direction between cities c1 and c2
 * The nodes for the cities must be present in the Graph
 * */
void AddFlight(graph* g, string c1, string c2, double miles) {
    // get the nodes of these 2 cities from the nodemap
    node* city1 = g->nodeMap[c1];
    node* city2 = g->nodeMap[c2];
    AddEdge(g, city1, city2, miles);
    AddEdge(g, city2, city1, miles);
}

/* Adds an edge from c1 -> c2, inserts that edge into the set:edges of the given graph, and the node c1  */
void AddEdge(graph* g, node* c1, node* c2, double cost) {
    edge* arc = new edge{};
    arc->start = c1;
    arc->finish = c2;
    arc->cost = cost;
    g->edges.insert(arc);
    c1->edges.insert(arc);
}

void VisitCity(node* city) {
    cout << city->name << endl;
}

void PrintAirlineGraph(graph* g) {
    for (node* city : g->nodes) {
        cout << city->name << " -> ";
        bool commaNeed = false;
        // Visit each neighboring node of this city (by iterating over the set of edges)
        for (edge* flight : city->edges) {
            if (commaNeed)
                cout << " , ";
            cout << flight->finish->name;
            commaNeed = true;
        }
        cout << endl;
    }
}
