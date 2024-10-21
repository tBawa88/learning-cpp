#pragma once

#include <iostream>
#include <string>

template <typename T>
struct Node {
    T val;
    Node* next;

    // constructors
    Node(const T& val);
    ~Node();
};

template <typename T>
Node<T>::Node(const T& val) {
    this->val = val;
    this->next = nullptr;
}

template <typename T>
Node<T>::~Node() { std::cout << val << "->Node deleted\n"; }
