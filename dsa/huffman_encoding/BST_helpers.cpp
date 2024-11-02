#include <iostream>
#include <stdexcept>

#include "BST.h"
using namespace std;

bool BST::contains(Treenode* node, const int& val) const {
    if (!node)
        return false;
    else if (node->data == val)
        return true;
    else if (val < node->data)
        return contains(node->left, val);
    else
        return contains(node->right, val);
}

void BST::insert(Treenode*& node, const int& val) {
    if (!node) {
        node = new Treenode(val);
        length++;
    } else if (val < node->data)
        insert(node->left, val);
    else if (val > node->data)
        insert(node->right, val);
    else {
        // val == node->data : ignore this case
    }
}

int BST::getMin(Treenode* node) const {
    if (node->left == nullptr)
        return node->data;
    else
        return getMin(node->left);
}
int BST::getMax(Treenode* node) const {
    if (node->right == nullptr)
        return node->data;
    else
        return getMax(node->right);
}

void BST::remove(Treenode*& node, const int& val) {
    if (!node) {
        throw runtime_error{"Node not found/Tree is empty"};
    } else if (val < node->data) {
        remove(node->left, val);
    } else if (val > node->data) {
        remove(node->right, val);
    } else {  // val == node->data
        // check all possible scenarios for this found node
        if (node->right == nullptr) {
            Treenode* trash = node;
            node = node->left;
            length--;
            delete trash;
        } else if (node->left == nullptr) {
            Treenode* trash = node;
            node = node->right;
            length--;
            delete trash;
        } else {
            // Meaning the node has both left and right subtree
            node->data = getMin(node->right);
            remove(node->right, node->data);
        }
    }
}

void BST::printSideways(Treenode* node, string indent) const {
    if (!node)
        return;

    printSideways(node->right, indent + "   ");
    cout << indent << node->data << endl;
    printSideways(node->left, indent + "   ");
}
void BST::print(Treenode* node) const {
    if (node) {
        print(node->left);
        cout << node->data << endl;
        print(node->right);
    }
}

void BST::clear(Treenode* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
