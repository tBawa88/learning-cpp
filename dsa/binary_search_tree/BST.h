#include <string>

#include "TreeNode.h"
#ifndef BST
#define BST
class BS_Tree {
    Treenode* root;
    size_t treesize;
    void insertHelper(Treenode*& node, const int& val);
    bool search(Treenode* node, const int& val);
    int getMin(Treenode* node) const;
    int getMax(Treenode* node) const;

    void inorderPrint(Treenode* node);
    void preorderPrint(Treenode* node);
    void postorderPrint(Treenode* node);
    void printSideways(Treenode* node, std::string indent);
    void clear(Treenode* node);

   public:
    BS_Tree();
    BS_Tree(Treenode* node);
    ~BS_Tree();
    BS_Tree* insert(int val);
    bool contains(int val);
    int getMin() const;
    int getMax() const;
    void remove(const int& val);

    void printPre();
    void printIn();
    void printPost();
    void printSideways();

    size_t size();
    bool empty();
};

#endif
