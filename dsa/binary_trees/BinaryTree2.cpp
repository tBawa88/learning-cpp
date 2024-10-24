#include "BinaryTree2.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
BinaryTree2::BinaryTree2() { cout << "Created a new tree\n"; }

BinaryTree2* BinaryTree2::insert(int val) {
    tree.push_back(val);
    return this;
}

bool BinaryTree2::contains(int val) {
    for (int x : tree)
        if (x == val)
            return true;

    return false;
}

size_t BinaryTree2::size() { return tree.size(); }
bool BinaryTree2::isEmpty() { return tree.empty(); }

void BinaryTree2::print() {
    printHelper(0);
}

void BinaryTree2::printSideways() {
    string indent = "";
    printHelper(0, "");
}

void BinaryTree2::printHelper(int rootIndex) {
    if (rootIndex < tree.size()) {
        cout << tree[rootIndex] << endl;
        // since we're storing values in an array just like a heap
        // index of the left child
        printHelper(rootIndex * 2 + 1);
        // index of the right child
        printHelper(rootIndex * 2 + 2);
    }
}
void BinaryTree2::printHelper(int rootIndex, string indent) {
    if (rootIndex < tree.size()) {
        printHelper(rootIndex * 2 + 1, indent + "   ");
        cout << indent << tree[rootIndex] << endl;
        printHelper(rootIndex * 2 + 2, indent + "   ");
    }
}
