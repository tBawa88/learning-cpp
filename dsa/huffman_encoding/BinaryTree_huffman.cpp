#include "BinaryTree_huffman.h"

#include <stdlib.h>

#include <iostream>
#include <string>

#include "Node.h"

BinaryTree::BinaryTree(Node* node) {
    root = node;
}

BinaryTree::~BinaryTree() { clear(root); }
void BinaryTree::printSideways() { printSideways(root, ""); }

void BinaryTree::printSideways(Node* node, std::string indent) {
    if (node) {
        printSideways(node->right, indent + "   ");
        if (node->ch != '`') {
            std::cout << indent;
            printf("%c -> %d\n", node->ch, node->priority);
        }
        printSideways(node->left, indent + "   ");
    }
}

void BinaryTree::clear(Node* node) {
    if (!node)
        return;

    clear(node->left);
    clear(node->right);
    delete node;
    node = nullptr;
}
