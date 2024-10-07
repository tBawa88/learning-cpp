#include <iostream>
#include <vector>

/**
 * Move all the zeroes to the end of array, without making the copy of array
 */

void swap(int& i, int& j) {
    i = i ^ j;
    j = i ^ j;
    i = i ^ j;
}

void moveZeroes(std::vector<int>& arr) {
    int nonzero = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonzero]);
            nonzero++;
        }
    }
}

/**
 * Another solution
 * 1. Find the index of first zero element
 * 2. Starting from it's next index, swap every non index with zero index while incrementing it on every swap
 */

void moveZeros2(std::vector<int>& arr) {
    int j = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            j = i;
            break;
        }
    }
    if (j == -1) return;

    for (int i = j + 1; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

void printvector(std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = {9, 1, 0, 3, 0, 8, 12};
    moveZeroes(v);
    printvector(v);

    return 0;
}
