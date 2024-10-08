#include <iostream>
#include <vector>
/**
 * SOLUTION:
 * This approach uses a vector to store a leaf node (the final combination for a decision path)
 * During the dry run of this problem, we're sort of building a """decision tree"""
 * One the left subtree, push all the 0s untill a leaf node (base case is encountered)
 * On the right subtree, push all the 1s untill a leaf node
 *
 * We're essentially doing a post-order tree traversal
 * Why post order? because we're first exhausting the left subtree and then the right subtree and then printing the output
 */

void print(std::vector<int>&);
void printBinary(int&, std::vector<int>&);

int main() {
    int n = 3;
    std::vector<int> arr;
    printBinary(n, arr);
    return 0;
}

void printBinary(int& n, std::vector<int>& arr) {
    if (arr.size() == n) {
        print(arr);
        return;
    }

    // left subtree of a node
    arr.push_back(0);
    printBinary(n, arr);
    arr.pop_back();

    // right subtree of a node
    arr.push_back(1);
    printBinary(n, arr);
    arr.pop_back();
}

void print(std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i;
    std::cout << std::endl;
}
