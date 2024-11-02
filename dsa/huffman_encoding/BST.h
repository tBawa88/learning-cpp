#include <string>

#include "Treenode.h"

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

class BST {
    Treenode* root;
    int length;

    // private helper methods
    bool contains(Treenode* node, const int& val) const;
    void insert(Treenode*& node, const int& val);
    void remove(Treenode*& node, const int& val);
    int getMin(Treenode* node) const;
    int getMax(Treenode* node) const;
    void printSideways(Treenode* node, std::string indent) const;
    void print(Treenode* node) const;
    void clear(Treenode* node);

   public:
    // constructors and destructors
    BST();
    BST(Treenode* root);
    ~BST();

    // main ADT methods
    bool contains(const int& val) const;
    void insert(const int& val);
    void remove(const int& val);
    int getMin() const;
    int getMax() const;
    void printSideways() const;
    void print() const;
    bool isEmpty() const;
    size_t size() const;
    void clear();
};

#endif
