#ifndef Tree_Node
#define Tree_Node

struct Treenode {
    int data;
    Treenode* left;
    Treenode* right;
    Treenode(const int& val);
    ~Treenode();
};

#endif
