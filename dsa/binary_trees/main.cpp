#include <iostream>

#include "BinaryTree.h"
#include "TreeNode.h"

using namespace std;

int main() {
    TreeNode *root = new TreeNode(10);
    root->leftchild = new TreeNode(20);
    root->rightchild = new TreeNode(30);

    root->leftchild->leftchild = new TreeNode(40);
    root->leftchild->rightchild = new TreeNode(50);

    root->rightchild->leftchild = new TreeNode(60);
    root->rightchild->rightchild = new TreeNode(70);

    BinaryTree tree{root};
    tree.print();
    int find{10};
    cout << "finding " << find << endl;

    if (tree.contains(find))
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";

    return 0;
}
