#include <iostream>

#ifndef P_Node
#define P_Node
struct Node {
    int data;
    int priority;

    Node(int data, int priority) : data{data}, priority{priority} {}
    ~Node() { std::cout << "pqueue node deleted \n"; }
};

#endif
