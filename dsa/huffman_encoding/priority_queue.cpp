#include "priority_queue.h"

#include <iostream>
#include <stdexcept>
using namespace std;

/**
 *    // Helper Methods
    void bubbleUp();
    void sinkDown();
    void swap(int a, int b);

   public:
    void enqueue(int value, int priority);
    int dequeue();
    size_t size();
    bool isEmpty();
    void print();
 */
size_t Queue::size() const { return list.size(); }
bool Queue::isEmpty() const { return list.size() == 0; }
Queue::~Queue() {
    for (Node* trash : list)
        delete trash;
}

void Queue::enqueue(int data, int priority) {
    list.push_back(new Node(data, priority));
    bubbleUp();
}
int Queue::dequeue() {
    if (isEmpty())
        throw runtime_error{"Queue is empty"};

    Node* firstNode = list[0];
    Node* lastNode = list[list.size() - 1];
    list[0] = lastNode;
    list.pop_back();
    sinkDown();
    return firstNode->data;
}

void Queue::bubbleUp() {
    int currIdx = list.size() - 1;
    int currPrio = list[currIdx]->priority;

    int parentIdx = (currIdx - 1) / 2;
    while (parentIdx >= 0 && list[parentIdx]->priority > currPrio) {
        swap(currIdx, parentIdx);
        currIdx = parentIdx;
        parentIdx = (currIdx - 1) / 2;
    }
}

int min(int a, int b) { return a < b ? a : b; }
void Queue::sinkDown() {
    if (list.size() < 2)
        return;

    int currIdx = 0;
    int currPrio = list[currIdx]->priority;
    int leftIdx = currIdx * 2 + 1;
    int rightIdx = min(leftIdx + 1, list.size() - 1);

    while (leftIdx < list.size()) {
        int smallerChildIdx = list[leftIdx]->priority < list[rightIdx]->priority ? leftIdx : rightIdx;
        if (currPrio < list[smallerChildIdx]->priority) break;

        swap(currIdx, smallerChildIdx);
        currIdx = smallerChildIdx;
        leftIdx = currIdx * 2 + 1;
        rightIdx = min(leftIdx + 1, list.size() - 1);
    }
}

void Queue::swap(int a, int b) {
    Node* temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

void Queue::print() const {
    for (Node* node : list)
        std::cout << node->data << ": Prio " << node->priority << std::endl;
}
