#include <iostream>
#include <vector>

#include "TreeNode.h"

#ifndef Binary_Tree
#define Binary_Tree

class BinaryTree {
    TreeNode* root;
    size_t treeSize;

   public:
    BinaryTree();
    BinaryTree(TreeNode* root);
    ~BinaryTree();

    void print();
    void printSideways();
    bool contains(int value);

    // void insert(int& val);
    // void removeLast();
};

#endif
