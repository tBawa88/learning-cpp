#ifndef Tree_Node
#define Tree_Node

struct Treenode {
    Treenode(const int& val);
    Treenode(Treenode* left, Treenode* right);
    ~Treenode();
    void setLeft(Treenode* left);
    void setRight(Treenode* right);

    int data;
    Treenode* left;
    Treenode* right;
};

#endif
