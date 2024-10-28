#include <iostream>

#include "BST.h"
#include "TreeNode.h"

using namespace std;
int main() {
    BS_Tree tree{new Treenode{10}};
    //                                                                      inserting a duplicate value
    tree.insert(5)->insert(15)->insert(6)->insert(2)->insert(11)->insert(20)->insert(6);

    cout << "==== printing ====\n";
    tree.printSideways();

    int find{11};
    if (tree.contains(find))
        cout << "FOUND " << find << endl;
    else
        cout << "NOT FOUND " << find << endl;

    cout << "Min value in tree = " << tree.getMin() << endl;
    cout << "Max value in tree = " << tree.getMax() << endl;

    int removeValue = 15;
    tree.remove(removeValue);
    tree.printSideways();
    return 0;
}
