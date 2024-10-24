#include "TreeNode.h"

#include <iostream>

Treenode::Treenode(const int& val, Treenode* left, Treenode* right) {
    this->data = val;
    this->left = left;
    this->right = right;
}

Treenode::~Treenode() { std::cout << "node deleted" << std::endl; }
