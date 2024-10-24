
#ifndef BST_TreeNode
#define BST_TreeNode
struct Treenode {
    int data;
    Treenode* left;
    Treenode* right;

    Treenode(const int& val,
             Treenode* left = nullptr,
             Treenode* right = nullptr);
    ~Treenode();
};

#endif
