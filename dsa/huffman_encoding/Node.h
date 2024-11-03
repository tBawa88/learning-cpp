#include <iostream>

#ifndef P_Node
#define P_Node
struct Node {
    char ch;
    int priority;
    Node* left;
    Node* right;

    Node(char ch, int priority) : ch{ch}, priority{priority} {
        left = nullptr;
        right = nullptr;
    }
    Node(int priority, Node* left, Node* right)
        : priority{priority}, left{left}, right{right} {}
    ~Node() {}
};

#endif
