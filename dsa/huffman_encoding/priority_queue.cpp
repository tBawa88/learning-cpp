#include "priority_queue.h"

#include <iostream>
#include <stdexcept>
using namespace std;

size_t Queue::size() const { return queueArray.size(); }
bool Queue::isEmpty() const { return queueArray.size() == 0; }
Queue::~Queue() {
    for (Node* trash : queueArray) {
        if (trash != nullptr) {
            delete trash;
            trash = nullptr;
        }
    }
}
// Takes a character and it's priority
// Creates a new Node*
// adds it to the Priority Queue
void Queue::enqueue(char ch, int priority) {
    queueArray.push_back(new Node(ch, priority));
    bubbleUp();
}

// Takes in a Node*
// adds it to the Priority Queue
void Queue::enqueue(Node* node) {
    queueArray.push_back(node);
    bubbleUp();
}

// Removes and Returns the lowest priority node from the queue
Node* Queue::dequeue() {
    if (isEmpty())
        throw runtime_error{"Queue is empty"};

    Node* firstNode = queueArray[0];
    Node* lastNode = queueArray[queueArray.size() - 1];
    queueArray[0] = lastNode;
    queueArray.pop_back();
    sinkDown();
    return firstNode;
}

// Helper methods =======

int min(int a, int b) { return a < b ? a : b; }

// Returns Whichever index has the smaller prio
int Queue::getSmallerPrioIndex(const int& leftIdx, const int& rightIdx) {
    if (queueArray[leftIdx]->priority < queueArray[rightIdx]->priority)
        return leftIdx;
    return rightIdx;
}

// Brings UP the last element of the underlying array
// Swaps current node with it's parent IF current node has lower priority value
void Queue::bubbleUp() {
    int currIdx = queueArray.size() - 1;
    int currPrio = queueArray[currIdx]->priority;

    int parentIdx = (currIdx - 1) / 2;
    while (parentIdx >= 0 && queueArray[parentIdx]->priority > currPrio) {
        swap(currIdx, parentIdx);
        currIdx = parentIdx;
        parentIdx = (currIdx - 1) / 2;
    }
}

// Sinks DOWN the 0th index node of the underlying array
// Swaps the current node with whichever child has the lower priority
//  - Only IF the current has higher priority value than both
void Queue::sinkDown() {
    if (queueArray.size() < 2)
        return;

    int currIdx = 0;
    int currPrio = queueArray[currIdx]->priority;
    int leftIdx = currIdx * 2 + 1;
    int rightIdx = min(leftIdx + 1, queueArray.size() - 1);

    while (leftIdx < queueArray.size()) {
        int smallerChildIdx = getSmallerPrioIndex(leftIdx, rightIdx);
        if (currPrio < queueArray[smallerChildIdx]->priority) break;

        swap(currIdx, smallerChildIdx);
        currIdx = smallerChildIdx;
        leftIdx = currIdx * 2 + 1;
        rightIdx = min(leftIdx + 1, queueArray.size() - 1);
    }
}

// Takes in 2 indices
// Swaps their position in the underlying array
void Queue::swap(int a, int b) {
    Node* temp = queueArray[a];
    queueArray[a] = queueArray[b];
    queueArray[b] = temp;
}

void Queue::print() const {
    for (Node* node : queueArray)
        printf("%c => %d\n", node->ch, node->priority);
}
