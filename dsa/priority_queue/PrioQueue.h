#include <math.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "Node.h"
// this node is diffy from the linked list node
#pragma once
int min(int a, int b) {
    return a < b ? a : b;
}

template <typename T>
class PrioQueue {
    // the heap is just a vector of Node pointers (all dynamically created)
    std::vector<Node<T>*> heap;
    void bubbleUp();
    void sinkDown();
    void swap(int a, int b);

   public:
    PrioQueue();
    ~PrioQueue();
    void enqueue(const T& val, int prio);
    T dequeue();
    T peek();
    int peekPriority();
    // void changePriority(const T& val, int prio);

    bool isEmpty();
    size_t size();
    void printqueue();
};

template <typename T>
PrioQueue<T>::PrioQueue() {}

template <typename T>
PrioQueue<T>::~PrioQueue() {
    for (Node<T>* node : heap) {
        delete node;
    }
}

template <typename T>
void PrioQueue<T>::swap(int a, int b) {
    auto temp = heap[a];
    heap[a] = heap[b];
    heap[b] = temp;
}
template <typename T>
void PrioQueue<T>::enqueue(const T& val, int prio) {
    Node<T>* newnode = new Node(val, prio);
    heap.push_back(newnode);
    bubbleUp();
}

template <typename T>
void PrioQueue<T>::bubbleUp() {
    int currIdx = heap.size() - 1;
    int currPrio = heap[currIdx]->priority;
    int parentIdx = (currIdx - 1) / 2;
    if (parentIdx < 0) return;

    int parentPrio = heap[parentIdx]->priority;

    while (parentIdx >= 0 && currPrio < parentPrio) {
        auto temp = heap[currIdx];
        heap[currIdx] = heap[parentIdx];
        heap[parentIdx] = temp;

        currIdx = parentIdx;
        parentIdx = (currIdx - 1) / 2;
        currPrio = heap[currIdx]->priority;
        parentPrio = heap[parentIdx]->priority;
    }
}

template <typename T>
T PrioQueue<T>::dequeue() {
    if (heap.empty()) {
        throw std::runtime_error{"dequeue(): priority queue is empty"};
    }

    if (heap.size() == 1) {
        Node<T>* temp = heap[0];
        heap.pop_back();
        T val = temp->val;
        delete temp;
        return val;
    }

    Node<T>* temp = heap[0];  // get reference to the first element
    heap[0] = heap[heap.size() - 1];  // update first element with last element
    heap.pop_back();  // remove the last element

    // perform the sink down operation
    sinkDown();

    // delete the node and return the value
    T val = temp->val;
    delete temp;
    return val;
}

template <typename T>
void PrioQueue<T>::sinkDown() {
    int currIdx = 0;
    int leftChildIdx = currIdx * 2 + 1;
    int rightChildIdx = min(heap.size() - 1, leftChildIdx + 1);

    int currPrio = heap[currIdx]->priority;
    int leftPrio = heap[leftChildIdx]->priority;
    int rightPrio = heap[rightChildIdx]->priority;
    int smallerIdx = leftPrio < rightPrio ? leftChildIdx : rightChildIdx;

    // untill the either the current node becomes the leaf node || currNode prio is less than both children nodes
    while (leftChildIdx < heap.size() && currPrio > heap[smallerIdx]->priority) {
        // swap current node with the child node that has the smaller prio
        swap(currIdx, smallerIdx);

        // re-calculate current, leftChild and rightChild index
        currIdx = smallerIdx;
        leftChildIdx = currIdx * 2 + 1;
        rightChildIdx = min(heap.size() - 1, leftChildIdx + 1);

        // obtain priorities
        currPrio = heap[currIdx]->priority;
        leftPrio = heap[leftChildIdx]->priority;
        rightPrio = heap[rightChildIdx]->priority;

        smallerIdx = leftPrio < rightPrio ? leftChildIdx : rightChildIdx;
    }
}

template <typename T>
T PrioQueue<T>::peek() {
    if (heap.empty()) {
        std::runtime_error{"peek(): priority queue is empty"};
    }
    return heap[0]->val;
}

template <typename T>
int PrioQueue<T>::peekPriority() {
    if (heap.empty()) {
        std::runtime_error{"peek(): priority queue is empty"};
    }

    int prio = heap[0]->priority;
    return prio;
}

template <typename T>
bool PrioQueue<T>::isEmpty() { return heap.empty(); }

template <typename T>
size_t PrioQueue<T>::size() { return heap.size(); }

template <typename T>
void PrioQueue<T>::printqueue() {
    for (auto node : heap) {
        std::cout << node->val << std::endl;
    }
}
