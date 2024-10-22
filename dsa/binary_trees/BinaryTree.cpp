#include "BinaryTree.h"

#include <iostream>

#include "TreeNode.h"

using namespace std;
void clearTree(TreeNode *root);
void printTree(TreeNode *root);
void containsHelper(TreeNode *root, int &value, bool &flag);
bool contains2(TreeNode *root, int &value);

BinaryTree::BinaryTree() {
    root = nullptr;
}
BinaryTree::BinaryTree(TreeNode *root) {
    this->root = root;
}
BinaryTree::~BinaryTree() {
    clearTree(root);
}

void BinaryTree::print() {
    printTree(root);
}

bool BinaryTree::contains(int value) {
    // method#1
    //  bool flag = false;
    //  containsHelper(root, value, flag);
    //  return flag;

    // method#2
    return contains2(root, value);
}

bool contains2(TreeNode *root, int &value) {
    if (!root)
        return false;
    else if (root->data == value)
        return true;
    else {
        // if the current node is neither nullptr or it doesn't contain the value, the value is either in the left subtree or the right
        // this statement is shortcircuiting (meaning the right function call will only be executed the value is not found in the left subtree)
        // if the leftSubtree returns false, only then explore the right subtree
        return contains2(root->leftchild, value) || contains2(root->rightchild, value);
    }
}

void clearTree(TreeNode *root) {
    if (root) {
        clearTree(root->leftchild);
        clearTree(root->rightchild);
        delete root;
    }
}
void printTree(TreeNode *root) {
    if (root) {
        cout << root->data << endl;
        printTree(root->leftchild);
        printTree(root->rightchild);
    }
}

void containsHelper(TreeNode *root, int &value, bool &flag) {
    // recursion will stop if either the flag has been set to true OR we've walked the whole tree
    if (root && !flag) {
        if (root->data == value) {
            // the moment the value is found, we end the recursion by setting the flat to true
            flag = true;
        }
        containsHelper(root->leftchild, value, flag);
        containsHelper(root->rightchild, value, flag);
    }
}
