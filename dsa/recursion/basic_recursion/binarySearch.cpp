#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& A, int val);
int searchHelper(std::vector<int>& A, int val, int low, int high);

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int val;
    std::cin >> val;
    int idx = binarySearch(v, val);

    if (idx == -1)
        std::cout << "Element NOT FOUND\n";
    else
        std::cout << "Element FOUND @" << idx << std::endl;

    return 0;
}

int binarySearch(std::vector<int>& v, int val) {
    int low = 0;
    int high = v.size() - 1;
    int mid = (low + high) / 2;
    return searchHelper(v, val, low, high);
}
int searchHelper(std::vector<int>& A, int val, int low, int high) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;
    if (val == A[mid])
        return mid;
    else if (val < A[mid])
        return searchHelper(A, val, low, mid - 1);
    else
        return searchHelper(A, val, mid + 1, high);
}
