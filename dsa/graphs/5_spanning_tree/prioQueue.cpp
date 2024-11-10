#ifndef _prio_queue
#define _prio_queue

#include <iostream>
#include <vector>

#include "graph.h"

using namespace std;

/**
 * Data structure : Priority queue
 * --------------------------------
 * This Priority Queue is specifically designed for finding Minimum spanning tree in a graph.
 * It stores a heap of edges in this version.
 *
 */

struct Node {
    edgeT* edge;
    double priority;

    Node(edgeT* edge, double prio) : edge{edge}, priority{prio} {}
};

class PrioQueue {
    vector<Node*> queue;
    void bubbleUp(int index);
    void sinkDown();
    void clear();
    int getSmallerPrioIndex(int a, int b);
    void swapElements(int a, int b);
    void printQueue();

   public:
    PrioQueue();
    ~PrioQueue();
    void enqueue(edgeT* edge, double priority);
    int findNodeIndex(edgeT* edge);
    void updatePriority(edgeT* edge, double newPrio);
    edgeT* dequeue();
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
int PrioQueue::findNodeIndex(edgeT* edge) {
    for (int i = 0; i < queue.size(); i++) {
        if (queue[i]->edge == edge)
            return i;
    }
    return -1;
}

/*Pqueue main ADT methods ----------------*/

void PrioQueue::enqueue(edgeT* edge, double priority) {
    Node* node = new Node(edge, priority);
    queue.push_back(node);
    bubbleUp(queue.size() - 1);
}
/**
 * If the given edge already exists in the queue, it's priority is updated
 * Otherwise, it's enqueue'd into the Priority queue
 */
void PrioQueue::updatePriority(edgeT* edge, double newPrio) {
    int idx = findNodeIndex(edge);
    if (idx != -1) {
        queue[idx]->priority = newPrio;
        bubbleUp(idx);
    } else {
        enqueue(edge, newPrio);
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

edgeT* PrioQueue::dequeue() {
    if (queue.empty())
        return nullptr;
    Node* firstNode = queue[0];
    Node* lastNode = queue[queue.size() - 1];
    queue[0] = lastNode;
    queue.pop_back();
    sinkDown();
    return firstNode->edge;
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
