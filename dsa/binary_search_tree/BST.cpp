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

//=========== all helper functions ===========
bool BS_Tree::insertHelper(Treenode* root, const int& val) {
    if (root) {
        if (val == root->data)
            return false;
        else if (val < root->data) {
            if (root->left == nullptr) {
                Treenode* newnode = new Treenode(val);
                root->left = newnode;
                treesize++;
                return true;
            } else
                return insertHelper(root->left, val);
        } else if (val > root->data) {
            if (root->right == nullptr) {
                Treenode* newnode = new Treenode(val);
                root->right = newnode;
                treesize++;
                return true;
            } else
                return insertHelper(root->right, val);
        }
    }
    return false;
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
