#include <vector>

#include "Node.h"

#ifndef Prio_Queue
#define Prio_Queue
class Queue {
    std::vector<Node*> queueArray;

    // Helper Methods
    void bubbleUp();
    void sinkDown();
    void swap(int a, int b);
    int getSmallerPrioIndex(const int& left, const int& right);

   public:
    ~Queue();
    void enqueue(char ch, int priority);
    void enqueue(Node* node);  // overloaded method for adding a new node in the list
    Node* dequeue();
    size_t size() const;
    bool isEmpty() const;
    void print() const;
};

#endif
