#include <vector>

#include "Node.h"

#ifndef Prio_Queue
#define Prio_Queue
class Queue {
    std::vector<Node*> list;

    // Helper Methods
    void bubbleUp();
    void sinkDown();
    void swap(int a, int b);

   public:
    ~Queue();
    void enqueue(int value, int priority);
    int dequeue();
    size_t size() const;
    bool isEmpty() const;
    void print() const;
};

#endif
