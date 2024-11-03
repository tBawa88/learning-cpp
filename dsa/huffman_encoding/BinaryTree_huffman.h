#include <string>

#include "Node.h"

#ifndef BinaryTree_Huffman
#define BinaryTree_Huffman

class BinaryTree {
    Node* root;
    void clear(Node* node);
    void printSideways(Node* node, std::string indent);

   public:
    BinaryTree(Node* node);
    ~BinaryTree();
    void printSideways();
};

#endif
