
#include "PrioQueue.h"

int main() {
    PrioQueue<int> pqueue;
    pqueue.enqueue(5, 5);
    pqueue.enqueue(25, 25);
    pqueue.enqueue(8, 8);
    pqueue.enqueue(13, 13);
    pqueue.enqueue(10, 10);
    pqueue.enqueue(2, 2);

    pqueue.printqueue();

    pqueue.dequeue();
    pqueue.dequeue();
    pqueue.dequeue();
    pqueue.dequeue();
    pqueue.dequeue();
    pqueue.dequeue();
    std::cout << "new queue" << std::endl;
    pqueue.printqueue();

    return 0;
}
