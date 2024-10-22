#include <iostream>

#ifndef Tree_Node
#define Tree_Node

using namespace std;
struct TreeNode {
    int data;
    TreeNode *leftchild;
    TreeNode *rightchild;

    TreeNode(int val,
             TreeNode *left = nullptr,
             TreeNode *right = nullptr);
    ~TreeNode();
};
#endif
