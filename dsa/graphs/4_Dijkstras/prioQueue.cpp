#ifndef _prio_queue
#define _prio_queue

#include <iostream>
#include <vector>

#include "graph.h"

using namespace std;

/**
 * Data structure : Priority queue
 * --------------------------------
 * This Priority queue version  is different from the earlier priority queue version.
 * We're not storing vectors in each node anymore
 * We're storing individual nodes and their shortest know paths as priorities
 *
 * Also the implementation is also very specific for this version of Dijkstra's
 * bubbleUp() -> bubbleUp(int index);
 * updatePrio(nodeT* vert, double newPrio);
 */

struct Node {
    nodeT* vertex;
    double priority;  // the total distance cost of the current path stored in this node

    Node(nodeT* vertex, double prio) : vertex{vertex}, priority{prio} {}
};

class PrioQueue {
    vector<Node*> queue;
    void bubbleUp(int index);  // for executing bubbleup on a specific array index
    void sinkDown();
    void clear();
    int getSmallerPrioIndex(int a, int b);
    void swapElements(int a, int b);
    void printQueue();

   public:
    PrioQueue();
    ~PrioQueue();
    void enqueue(nodeT* vertex, double priority);
    int findNodeIndex(nodeT* vertex);
    /*If the node Vertex exists in the queue, then it's prio is updated, else enqueue() is called */
    void updatePriority(nodeT* vertex, double newPrio);
    nodeT* dequeue();
    bool empty();
};

/*Pqueue ADT helper methods------------------*/
PrioQueue::PrioQueue() {};
PrioQueue::~PrioQueue() { clear(); }
void PrioQueue::clear() {
    for (Node* pNode : queue)
        delete pNode;
    queue.clear();
}
void PrioQueue::swapElements(int a, int b) {
    Node* temp = queue[a];
    queue[a] = queue[b];
    queue[b] = temp;
}
bool PrioQueue::empty() { return queue.empty(); }
int min(int a, int b) { return a < b ? a : b; }
int PrioQueue::getSmallerPrioIndex(int a, int b) {
    return queue[a]->priority < queue[b]->priority ? a : b;
}
int PrioQueue::findNodeIndex(nodeT* vertex) {
    for (int i = 0; i < queue.size(); i++) {
        if (queue[i]->vertex == vertex)
            return i;
    }
    return -1;
}

/*Pqueue main ADT methods ----------------*/
void PrioQueue::enqueue(nodeT* vertex, double priority) {
    Node* node = new Node(vertex, priority);
    queue.push_back(node);
    bubbleUp(queue.size() - 1);
}
void PrioQueue::updatePriority(nodeT* vertex, double newPrio) {
    int idx = findNodeIndex(vertex);
    if (idx != -1) {
        queue[idx]->priority = newPrio;
        bubbleUp(idx);
    } else {
        enqueue(vertex, newPrio);
    }
}
void PrioQueue::bubbleUp(int currIdx) {
    if (currIdx < 0 || currIdx >= queue.size())
        return;
    double currPrio = queue[currIdx]->priority;
    int parentIdx = (currIdx - 1) / 2;
    while (parentIdx >= 0) {
        double parentPrio = queue[parentIdx]->priority;
        if (parentPrio <= currPrio) break;

        swapElements(currIdx, parentIdx);
        currIdx = parentIdx;
        parentIdx = (currIdx - 1) / 2;
    }
}

nodeT* PrioQueue::dequeue() {
    if (queue.empty())
        return nullptr;
    Node* firstNode = queue[0];
    Node* lastNode = queue[queue.size() - 1];
    queue[0] = lastNode;
    queue.pop_back();
    sinkDown();
    return firstNode->vertex;
}

void PrioQueue::sinkDown() {
    if (queue.size() < 2)
        return;
    int currIdx = 0;
    int currPrio = queue[currIdx]->priority;
    int leftIdx = currIdx * 2 + 1;
    int rightIdx = min(leftIdx + 1, queue.size() - 1);

    while (leftIdx < queue.size()) {
        int smallerIdx = getSmallerPrioIndex(leftIdx, rightIdx);
        if (currPrio < queue[smallerIdx]->priority) break;

        swapElements(currIdx, smallerIdx);
        currIdx = smallerIdx;
        leftIdx = currIdx * 2 + 1;
        rightIdx = min(leftIdx + 1, queue.size() - 1);
    }
}

#endif
