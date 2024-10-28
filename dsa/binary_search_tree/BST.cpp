#include "BST.h"

#include <iostream>

#include "TreeNode.h"
using namespace std;

BS_Tree::BS_Tree() : root{nullptr}, treesize{0} {}
BS_Tree::BS_Tree(Treenode* root) : root{root}, treesize{1} {}

BS_Tree::~BS_Tree() {
    clear(root);
    treesize = 0;
}

// Recursively inserts a value into the BSTree
// It only stores unique values just like the 'set' data structure from STL
BS_Tree* BS_Tree::insert(int val) {
    insertHelper(root, val);
    return this;
}
// Returns true if the value is found in the BSTree
bool BS_Tree::contains(int val) { return search(root, val); }

size_t BS_Tree::size() { return treesize; }
bool BS_Tree::empty() { return treesize == 0; }

// Prints In-Order traversal of the BSTree
void BS_Tree::printIn() { inorderPrint(root); }

// Prints Post-rder traversal of the BSTree
void BS_Tree::printPost() { postorderPrint(root); }

// Prints Pre-Order traversal of the BSTree
void BS_Tree::printPre() { preorderPrint(root); }

// Prints the Entire Tree sideways with proper indentation
void BS_Tree::printSideways() {
    printSideways(root, "");
}

int BS_Tree::getMin() const {
    if (!root)
        throw runtime_error{"Tree is empty"};
    return getMin(root);
}
int BS_Tree::getMax() const {
    if (!root)
        throw runtime_error{"Tree is empty"};
    return getMax(root);
}

//=========== all helper functions ===========
void BS_Tree::insertHelper(Treenode*& root, const int& val) {
    // passing reference to a pointer which allows us to update the nullptr directly (not derefrence it, but update it's value)
    if (!root) {
        root = new Treenode{val};
        treesize++;
    } else if (root->data > val) {
        insertHelper(root->left, val);
    } else if (root->data < val) {
        insertHelper(root->right, val);
    }
    // ignore the case where root->data == val
}

bool BS_Tree::search(Treenode* root, const int& val) {
    if (root) {
        if (root->data == val)
            return true;
        else if (root->data > val)
            return search(root->left, val);  // search left subtree
        else
            return search(root->right, val);  // search right subtree
    }
    // if the current node is nullptr, means this is where the node was supposed to be if it exisited in the BST
    return false;
}

int BS_Tree::getMax(Treenode* node) const {
    if (!node->right)
        return node->data;
    else
        return getMax(node->right);
}
int BS_Tree::getMin(Treenode* node) const {
    if (!node->left)
        return node->data;
    else
        return getMin(node->left);
}

// ==== Print Helpers ======

void BS_Tree::printSideways(Treenode* node, string indent) {
    if (node) {
        printSideways(node->right, indent + "   ");
        cout << indent << node->data << endl;
        printSideways(node->left, indent + "   ");
    }
}
void BS_Tree::inorderPrint(Treenode* root) {
    if (root) {
        inorderPrint(root->left);
        cout << root->data << " , ";
        inorderPrint(root->right);
    }
}
void BS_Tree::preorderPrint(Treenode* root) {
    if (root) {
        cout << root->data << " , ";
        inorderPrint(root->left);
        inorderPrint(root->right);
    }
}
void BS_Tree::postorderPrint(Treenode* root) {
    if (root) {
        inorderPrint(root->left);
        inorderPrint(root->right);
        cout << root->data << " , ";
    }
}
void BS_Tree::clear(Treenode* root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}
