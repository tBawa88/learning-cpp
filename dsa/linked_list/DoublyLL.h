#pragma once

#include <iostream>
#include <stdexcept>

#include "Node.h"

class DLinkedList {
    Node<int> *head;
    size_t length;

   public:
    DLinkedList();
    ~DLinkedList();
};
