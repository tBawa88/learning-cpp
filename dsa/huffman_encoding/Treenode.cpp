#include "Treenode.h"

#include <iostream>

Treenode::Treenode(const int& val) {
    data = val;  // copy assignment
    left = nullptr;
    right = nullptr;
}

Treenode::~Treenode() {
    std::cout << "node destroyed ->" << data << std::endl;
}

void Treenode::setLeft(Treenode* left) {
    this->left = left;
}
void Treenode::setRight(Treenode* right) {
    this->right = right;
}
