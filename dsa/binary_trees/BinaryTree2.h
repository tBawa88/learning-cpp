#include <string>
#include <vector>

// instead of storing TreeNode as these structs and having them store pointers to the left and right child
// we can create a binary tree class which uses an array/vector as it's underlying data structure
// with this we'll be implementing a complete binary tree where each level maybe except the last is completely filled
#ifndef Binary_Tree_2
#define Binary_Tree_2
class BinaryTree2 {
    std::vector<int> tree;
    // Recursively prints a Binary Tree, takes in the root index
    void printHelper(int rootIndex);
    // Recursively prints the Binary Tree 'Sideways' with proper indentation
    void printHelper(int rootIndex, std::string indent);

   public:
    BinaryTree2();
    BinaryTree2* insert(int val);
    bool contains(int val);
    size_t size();
    bool isEmpty();
    void print();
    void printSideways();
};
#endif
