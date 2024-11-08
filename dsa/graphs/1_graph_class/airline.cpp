#include <iostream>
#include <map>
#include <set>
#include <string>

#include "graph.h"
using namespace std;

template <typename Nodetype, typename Edgetype>
Graph<Nodetype, Edgetype>* CreateAirlineGraph();

template <typename NodeType, typename EdgeType>
void AddFlight(Graph<NodeType, EdgeType>* g, string city1, string city2, double miles);

template <typename NodeType, typename EdgeType>
void AddCity(Graph<NodeType, EdgeType>* g, string name);

template <typename Nodetype, typename Edgetype>
Graph<Nodetype, Edgetype>* CreateAirlineGraph() {
    Graph<Nodetype, Edgetype>* g = new Graph<Nodetype, Edgetype>{};
    AddCity(g, "Atlanta");
    AddCity(g, "Boston");
    AddCity(g, "Chicago");
    AddCity(g, "Dallas");
    AddCity(g, "Denver");
    AddCity(g, "Los Angeles");
    AddCity(g, "New York");
    AddCity(g, "Portland");
    AddCity(g, "San Francisco");
    AddCity(g, "Seattle");
    AddFlight(g, "Atlanta", "Chicago", 599);
    AddFlight(g, "Atlanta", "Dallas", 725);
    AddFlight(g, "Atlanta", "New York", 756);
    AddFlight(g, "Boston", "New York", 191);
    AddFlight(g, "Boston", "Seattle", 2489);
    AddFlight(g, "Chicago", "Denver", 907);
    AddFlight(g, "Dallas", "Denver", 650);
    AddFlight(g, "Dallas", "Los Angeles", 1240);
    AddFlight(g, "Dallas", "San Francisco", 1468);
    AddFlight(g, "Denver", "San Francisco", 954);
    AddFlight(g, "Portland", "Seattle", 130);
    AddFlight(g, "Portland", "San Francisco", 550);

    return g;
}
/**
 * Function : AddCity
 * Usage : AddCity(g, "city_name");
 * --------------------------------
 * It calls g->addNode() and adds a new node into the Graph with given name
 */
template <typename NodeType, typename EdgeType>
void AddCity(Graph<NodeType, EdgeType>* g, string name) {
    g->addNode(name);
}
/**
 * Function : AddFlight
 * Usage : AddFlight(g, "city1", "city2");
 * ------------------------------------
 * It calls g->addEdge(), and creates a bi-directional edge between city1 and city2
 */
template <typename NodeType, typename EdgeType>
void AddFlight(Graph<NodeType, EdgeType>* g, string city1, string city2, double miles) {
    g->addEdge(city1, city2, miles);
    g->addEdge(city2, city1, miles);
}
