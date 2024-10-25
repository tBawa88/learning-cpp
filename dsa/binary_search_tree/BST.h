#include <string>

#include "TreeNode.h"
#ifndef BST
#define BST
class BS_Tree {
    Treenode* root;
    size_t treesize;
    void insertHelper(Treenode*& root, const int& val);
    bool search(Treenode* root, const int& val);
    void inorderPrint(Treenode* root);
    void preorderPrint(Treenode* root);
    void postorderPrint(Treenode* root);
    void clear(Treenode* root);

   public:
    BS_Tree();
    BS_Tree(Treenode* root);
    ~BS_Tree();
    BS_Tree* insert(int val);
    bool contains(int val);

    void printPre();
    void printIn();
    void printPost();
    size_t size();
    bool empty();
};

#endif
