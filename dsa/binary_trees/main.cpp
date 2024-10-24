#include <iostream>

#include "BinaryTree.h"
#include "BinaryTree2.h"
#include "TreeNode.h"
using namespace std;

int main() {
    BinaryTree2 tree;
    tree.insert(10)
        ->insert(20)
        ->insert(30)
        ->insert(40)
        ->insert(50)
        ->insert(60)
        ->insert(70);

    cout << "---- print ---- " << endl;
    tree.print();

    cout << "---- print sideways ---- " << endl;
    tree.printSideways();

    int find{10};
    if (tree.contains(find))
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";

    return 0;
}

int main_asdasd() {
    TreeNode *root = new TreeNode(10);
    root->leftchild = new TreeNode(20);
    root->rightchild = new TreeNode(30);

    root->leftchild->leftchild = new TreeNode(40);
    root->leftchild->rightchild = new TreeNode(50);

    root->rightchild->leftchild = new TreeNode(60);
    root->rightchild->rightchild = new TreeNode(70);

    BinaryTree tree{root};
    cout << "==== print ====\n";
    tree.print();

    cout << "==== printSideways ====\n";
    tree.printSideways();

    int find{10};
    cout << "finding " << find << endl;

    if (tree.contains(find))
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";

    return 0;
}
