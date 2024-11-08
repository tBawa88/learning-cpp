#ifndef _prio_queue
#define _prio_queue

#include <vector>

#include "graph.h"

using namespace std;

struct Node {
    vector<edgeT*> path;
    double priority;  // the total distance cost of the current path stored in this node

    Node(vector<edgeT*> path, double prio) : path{path}, priority{prio} {}
};

class PrioQueue {
    vector<Node*> queue;
    void bubbleUp();
    void sinkDown();
    void clear();
    int getSmallerPrioIndex(int a, int b);
    void swapElements(int a, int b);

   public:
    PrioQueue();
    ~PrioQueue();
    void enqueue(vector<edgeT*> path, double priority);
    vector<edgeT*> dequeue();
    bool empty();
};
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

void PrioQueue::enqueue(vector<edgeT*> path, double priority) {
    Node* node = new Node(path, priority);
    queue.push_back(node);
    bubbleUp();
}
vector<edgeT*> PrioQueue::dequeue() {
    if (queue.empty())
        return vector<edgeT*>{};
    Node* firstNode = queue[0];
    Node* lastNode = queue[queue.size() - 1];
    queue[0] = lastNode;
    queue.pop_back();
    sinkDown();
    return firstNode->path;
}

void PrioQueue::bubbleUp() {
    int currIdx = queue.size() - 1;
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

int min(int a, int b) { return a < b ? a : b; }
int PrioQueue::getSmallerPrioIndex(int a, int b) {
    return queue[a]->priority < queue[b]->priority ? a : b;
}
void PrioQueue::sinkDown() {
    if (queue.size() < 2)
        return;
    int currIdx = 0;
    int currPrio = queue[currIdx]->priority;
    int leftIdx = currPrio * 2 + 1;
    int rightIdx = min(leftIdx + 1, queue.size() - 1);
    while (leftIdx < queue.size()) {
        int smallerIdx = getSmallerPrioIndex(leftIdx, rightIdx);
        if (currPrio <= queue[smallerIdx]->priority) break;

        swapElements(currIdx, smallerIdx);
        currIdx = smallerIdx;
        leftIdx = currIdx * 2 + 1;
        rightIdx = min(leftIdx + 1, queue.size() - 1);
    }
}

#endif
