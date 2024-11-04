#include <string>
#include <unordered_map>

#include "Node.h"

#ifndef BinaryTree_Huffman
#define BinaryTree_Huffman

class BinaryTree {
    Node* root;
    void clear(Node* node);
    void printSideways(Node* node, std::string indent);
    void mapBinaryCode(Node* node, std::unordered_map<char, std::string>& huffmanCodes, std::string binaryCode);

   public:
    BinaryTree(Node* node);
    ~BinaryTree();
    void mapBinaryCode(std::unordered_map<char, std::string>& huffmanCodes);
    void printSideways();
};

#endif
