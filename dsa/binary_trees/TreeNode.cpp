#include "TreeNode.h"

TreeNode::TreeNode(int val, TreeNode *left, TreeNode *right) {
    data = val;
    leftchild = left;
    rightchild = right;
}

TreeNode ::~TreeNode() {
    cout << data << "->Node deleted\n";
}
