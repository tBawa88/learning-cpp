#pragma once

#include <iostream>
#include <stdexcept>
// #include <string>

#include "Node.h"

template <typename T>
class LinkedList {
    Node<T>* head;
    size_t length;

   public:
    LinkedList();
    ~LinkedList();
    void push_back(const T& val);
    void push_front(const T& val);
    void insert(int idx, const T& val);

    void pop_back();
    void pop_front();
    void remove(int idx);

    T& get(int idx);
    void set(int idx, T& val);

    bool isEmpty() { return length == 0; }
    size_t size() { return this->length; }
    void printlist();
    // std::string& toString();
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = head;
    while (curr) {
        Node<T>* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::push_back(const T& val) {
    Node<T>* newnode = new Node(val);
    if (!head) {
        head = newnode;
        ++length;
        return;
    }

    Node<T>* curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = newnode;
    ++length;
}

template <typename T>
void LinkedList<T>::push_front(const T& val) {
    Node<T>* newnode = new Node(val);
    if (!head) {
        head = newnode;
        ++length;
        return;
    }

    newnode->next = head;
    head = newnode;
    ++length;
}

template <typename T>
void LinkedList<T>::insert(int idx, const T& val) {
    if (idx < 0 || idx >= length)
        throw std::runtime_error{"insert() : invalid index"};

    if (idx == 0) {
        push_front(val);
        return;
    }

    if (idx == length - 1) {
        push_back(val);
        return;
    }
    // insert in the middle
    Node<T>* newnode = new Node(val);
    Node<T>* curr = head;
    Node<T>* prev = nullptr;
    while (idx > 0) {
        prev = curr;
        curr = curr->next;
        idx--;
    }

    prev->next = newnode;
    newnode->next = curr;
    ++length;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (!head)
        throw std::runtime_error{"pop_front(): list is empty"};

    Node<T>* temp = head;
    head = head->next;
    delete temp;
    --length;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (!head)
        throw std::runtime_error{"pop_back() : list is empty"};

    Node<T>** curr = &head;
    while ((*curr)->next) {
        curr = &((*curr)->next);
    }
    delete (*curr);
    *curr = nullptr;
    --length;
}

template <typename T>
void LinkedList<T>::remove(int idx) {
    if (idx < 0 || idx >= length)
        throw std::runtime_error{"remove(): invalid list index"};

    if (idx == 0) {
        pop_front();
        return;
    }
    if (idx == length - 1) {
        pop_back();
        return;
    }
    // remove from the middle
    Node<T>** curr = &head;
    while (idx > 0) {
        curr = &((*curr)->next);
        --idx;
    }
    Node<T>* temp = *curr;
    *curr = (*curr)->next;
    delete temp;
    --length;
}

template <typename T>
T& LinkedList<T>::get(int idx) {
    if (idx < 0 || idx >= length)
        throw std::runtime_error{"get(): invalid list index"};

    Node<T>* curr = head;
    while (idx > 0) {
        curr = curr->next;
        idx--;
    }
    return curr->val;
}

template <typename T>
void LinkedList<T>::set(int idx, T& val) {
    if (idx < 0 || idx >= length)
        throw std::runtime_error{"set() : invalid list index"};

    Node<T>* curr = head;
    while (idx > 0) {
        curr = curr->next;
        idx--;
    }
    curr->val = val;
}

template <typename T>
void LinkedList<T>::printlist() {
    Node<T>* curr = head;
    while (curr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }
}
