/**
 * File : Graph.h
 * ---------------
 * Extended interface for the Graph package.
 * It contains both the graphT interface which lets the client make their own implmenation of the Graph DS
 * It also contains the Graph class, which is a fully implmented Graph ADT, whith methods and whatnot
 */
#ifndef _graph_class_
#define _graph_class_

#include <map>
#include <set>
#include <string>

struct nodeT; /*Forward references for the compiler*/
struct edgeT;

struct graphT {
    std::set<nodeT*> nodes;
    std::set<edgeT*> edges;
    std::map<std::string, nodeT*> nodeMap;
};
struct nodeT {
    std::string name;
    std::set<edgeT*> edges;
};
struct edgeT {
    nodeT* start;
    nodeT* finish;
    double cost;
};

/**
 * Class : Graph<NodeType, EdgeType>
 * --------------------------------
 * This class represents a generic Graph class, which takes in user implemented NodeType and EdgeType parameters
 * These types can contain whatever additional fields and methods required by Client's use case, but they must contain
 * the following public fields required by the Graph class for proper implementation of the Graph data structure
 *
 * The NodeType definition must include:
 *   - A string field called name
 *   - A Set<EdgeType *> field called edges
 *
 * The EdgeType definition must include:
 *   - A NodeType * field called start
 *   - A NodeType * field called finish
 *   - A double field called cost
 */
template <typename NodeType, typename EdgeType>
class Graph {
   public:
    /**
     * Constructor : Graph
     * Usage : Graph<NodeType, EdgeType> g;
     * -----------------------------------
     * declares a new variable of type Graph named g
     */
    Graph();

    /**
     * Destructor : ~Graph
     * Usage : (usually implicit)
     * ---------------------------------------------------------------------------------
     * Frees the storage for all the nodes and edges that are dynamically allocated on the heap
     */
    ~Graph();

    /**
     * Method: clear
     * Usage : g.clear();
     * ------------------
     * Frees the storage for all the node and edges in the graph. Re-inits the Graph to be empty
     */
    void clear();

    /**
     * Method : addNode
     * Usage : g.addNode(name);
     *         g.addNode(node);
     * ------------------------
     * Adds a new node to the graph.
     * The First version takes in a string, creates a new node of appropriate type and initializes it's name field with the given string.
     * The Second version assumes the client has already created a node and directly adds this node to the Graph.
     * Both versions of this method return the NodeType*, incase the client needs to capture this value
     */
    NodeType* addNode(std::string name);
    NodeType* addNode(NodeType* node);

    /**
     * Method : addEdge
     * Usage : g.addEdge(s1, s2);
     *         g.addEdge(n1, n2);
     *         g.addEdge(edge);
     * --------------------------
     * Creates a new edge between two nodes and adds it to the set of edges in the Graph
     * The endpoints of the edge can be specified either using a string name of the Node OR
     * by NodeType* pointers.
     * The third version assumes that the user has crated an EdgeType and directly adds it to the Graph's set of edges
     * All versions return the pointer to the EdgeType* incase the client needs to capture this value
     */
    EdgeType* addEdge(std::string node1, std::string node2, double cost);
    EdgeType* addEdge(NodeType* node1, NodeType* node2, double cost);
    EdgeType* addEdge(EdgeType* edge);

    /**
     * Method : isConnected
     * Usgage : if(g.isConnected(s1, s2)) . . .
     *          if(g.isConnected(n1, n2)) . . .
     * ----------------------------------------
     * Returns true if the Graph contains an Edge from node1 to node2
     * Nodes can be specified either by their names or NodeType* pointers
     */
    bool isConnected(std::string node1, std::string node2);
    bool isConnected(NodeType* node1, NodeType* node2);

    /**
     * Method : getNode
     * Usage : NodeType* node = g.getNode(name)
     * -------------------------------------
     * Returns the node that has the provided name. If no such node exists in the Graph, it returns nullptr
     */
    NodeType* getNode(std::string name);

    /**
     * Method : getNodeSet
     * Usage : for (NodeType* node : g.getNodeSet()) . . .
     * ----------------------------------------------------
     * Returns the set that contains all the nodes inside the Graph
     */
    std::set<NodeType*>& getNodeSet();

    /**
     * Method : getEdgeSet
     * Usage : for(EdgeType* edge : g.getEdgeSet()) . . .
     *         for (EdgeType* edge : g.getEdgeSet(node)). . .
     * ----------------------------------------------------
     * Returns the set of all the edges present in the graph,
     * If a node is passed as a parameter, it returns set of edges of that node
     */
    std::set<EdgeType*>& getEdgeSet();
    std::set<EdgeType*>& getEdgeSet(NodeType* node);

   private:
    std::set<NodeType*> nodes;
    std::set<EdgeType*> edges;
    std::map<std::string, NodeType*> nodeMap;
};

// Since we're implementing a templated class, we need to include the implementation inside the header file
// OR else the linker won't be able to find the template implementation
// C++ is just so amazing
#include "graph_impl.cpp"

#endif
