#include <iostream>
#include <vector>

/**
 * The idea of binary search over a sorted array/ or a binary search tree (which is almost the same thing as a sorted array)
 * is very simple : we don't have to seach each element 1 by 1 from the starting to end
 * We start from the middle. If the value we're searching is less than the middle element, then the value will be found in the left half of array
 * If the value is greater than the middle of the element, it'll be found in the right half ot the array
 * Each itreation we keep HALVING the array (divide and conquer)
 * It runs in O(logN) time and is wayyyy faster than linear search.
 */

int binarySearch(std::vector<int>& arr, int val);
int binarySearchRecursive(std::vector<int>& arr, int val);
int helper(std::vector<int>& arr, int val, int low, int mid, int high);
int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 44, 55};
    // int val = binarySearch(v, 12);
    int val = binarySearchRecursive(v, 1);

    std::cout << "found value " << val << std::endl;
}

/**
 * If the mid element is the value we're looking for, return it
 * IF value is GT mid element, move up low to just right of mid index, update mid and repeat
 * IF value is LT mid element, move down high to just left of mid index, update mid and repeat
 *
 */
int binarySearch(std::vector<int>& arr, int val) {
    int low = 0;
    int high = arr.size() - 1;
    int mid = (low + high) / 2;

    while (low <= high) {
        if (arr[mid] == val) {
            return val;
        } else if (val < arr[mid]) {
            high = mid - 1;
            mid = (low + high) / 2;
        } else {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }

    return -1;
}

int binarySearchRecursive(std::vector<int>& arr, int val) {
    int low = 0;
    int high = arr.size() - 1;
    int mid = (low + high) / 2;
    return helper(arr, val, low, mid, high);
}

int helper(std::vector<int>& arr, int val, int low, int mid, int high) {
    if (low > high) {
        return -1;
    } else if (val == arr[mid]) {
        return arr[mid];
    } else if (val < arr[mid]) {
        high = mid - 1;
        mid = (low + high) / 2;
        return helper(arr, val, low, high, mid);
    } else {
        low = mid + 1;
        mid = (low + high) / 2;
        return helper(arr, val, low, mid, high);
    }
}
