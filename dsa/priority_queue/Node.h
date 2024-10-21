#pragma once

#include <iostream>
#include <string>

template <typename T>
struct Node {
    T val;
    int priority;
    // constructors
    Node(const T& val, int prio);
    ~Node();
};

template <typename T>
Node<T>::Node(const T& val, int prio) {
    this->val = val;
    priority = prio;
}

template <typename T>
Node<T>::~Node() { std::cout << val << "->Node deleted\n"; }
