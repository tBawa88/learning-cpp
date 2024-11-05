#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

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
    void decompressFile(const std::string& decompFile, std::vector<bool>& bits) const;
    void printSideways();
};

#endif
