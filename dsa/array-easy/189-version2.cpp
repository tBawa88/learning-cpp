#include <algorithm>
#include <iostream>
#include <vector>

/**
 * This version doesn't use any extra space, but since we're reversing the array twice, it takes O(2n) time
 */

void leftRotate(std::vector<int>& arr, int k) {
    std::reverse(arr.begin(), arr.end() - k);
    std::reverse(arr.begin() + arr.size() - k, arr.end());
    std::reverse(arr.begin(), arr.end());

    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

void printvector(std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    printvector(arr);
    leftRotate(arr, 3);

    return 0;
}
