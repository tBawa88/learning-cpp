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

// Removes the given value from the Tree. If value is not found, exception is thrown
void BS_Tree::remove(const int& val) {
    if (!root)
        throw runtime_error{"Tree is empty"};
    remove(root, val);
    cout << "value removed from tree => " << val << endl;
}

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
void BS_Tree::insertHelper(Treenode*& node, const int& val) {
    if (!node) {
        // Now this node is either the leftchild or the rightchild
        // passing reference to a pointer allows us to directly update value of 'leftchild/rightchild field' from nullptr to a new Treenode*)
        node = new Treenode{val};
        treesize++;
    } else if (node->data > val) {
        insertHelper(node->left, val);
    } else if (node->data < val) {
        insertHelper(node->right, val);
    }
    // ignore the case where root->data == val; no duplicates allowed
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

void BS_Tree::remove(Treenode*& node, const int& val) {
    if (node == nullptr)
        throw runtime_error{"Value not found in the tree"};
    else if (node->data > val)
        remove(node->left, val);
    else if (node->data < val)
        remove(node->right, val);
    else {  // node->data == val
        if (node->right == nullptr) {
            // meaning node has no right subtree, simply make the current node point to it's right child
            // since it's a reference to pointer, this step will change the actual link (meaning the parent, if any, will point to it's left child)
            Treenode* trash = node;
            node = node->left;
            delete trash;
        } else if (node->left == nullptr) {
            // meaning the node has no left child, do the same thing
            Treenode* trash = node;
            node = node->right;
            delete trash;
        } else {
            node->data = getMin(node->right);
            // now walk the right subtree and recursively reach THAT node that returned us the value getMin()
            remove(node->right, node->data);
        }
    }
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
