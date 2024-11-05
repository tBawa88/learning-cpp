#include "BinaryTree_huffman.h"

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Node.h"

using namespace std;

BinaryTree::BinaryTree(Node* node) {
    root = node;
}

BinaryTree::~BinaryTree() { clear(root); }
void BinaryTree::printSideways() { printSideways(root, ""); }

// Walks the Huffman Tree, obtains the binary code for each character stored and stores it in a map
void BinaryTree::mapBinaryCode(std::unordered_map<char, std::string>& huffmanCodes) {
    mapBinaryCode(root, huffmanCodes, "");
}

void BinaryTree::decompressFile(const string& decompFile, vector<bool>& bits) const {
    ofstream srcFile(decompFile);
    if (!srcFile)
        throw runtime_error{"Failed to create decompressed file"};

    Node* node = root;
    for (bool bit : bits) {
        if (node->right == nullptr && node->left == nullptr) {
            srcFile << node->ch;
            node = root;
        }

        if (bit)
            node = node->right;
        else
            node = node->left;
    }

    srcFile.close();
}

// Perform  a post-order tarversal, hit all the leaf nodes and map each character to it's binary code (path taken to reach it)
void BinaryTree::mapBinaryCode(Node* node, std::unordered_map<char, std::string>& huffmanCodes, std::string binaryCode) {
    if (!node)
        return;

    // If you go left, append 0 to the binary code
    mapBinaryCode(node->left, huffmanCodes, binaryCode + '0');
    // If you go right, append 1 to the binary code
    mapBinaryCode(node->right, huffmanCodes, binaryCode + '1');
    // If it's the leaft node, map it to the binary string accumulated so far
    if (node->left == nullptr && node->right == nullptr) {
        huffmanCodes[node->ch] = binaryCode;
    }
}

void BinaryTree::printSideways(Node* node, std::string indent) {
    if (node) {
        printSideways(node->right, indent + "   ");
        std::cout << indent;
        printf("%c -> %d\n", node->ch, node->priority);
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
