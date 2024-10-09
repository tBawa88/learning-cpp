#include <iostream>
#include <string>
#include <vector>
/**
 * Since both the arrays are sorted, simply merge them using the 2 pointer approach
 * Just make sure to place an ifcheck before adding element to the result vector
 * The last element of the vector should not be same as current vector
 * Since both the arrays are sorted, we only need to compare the latest element added to the vector
 */

void unionOfArrays(std::vector<int>&, std::vector<int>&, std::vector<int>&);
void print(std::vector<int>&);

int main() {
    std::vector<int> arr1 = {1, 1, 2, 3, 3, 4, 5};
    std::vector<int> arr2 = {1, 3, 4, 5, 6};
    std::vector<int> result;
    unionOfArrays(arr1, arr2, result);
    print(result);

    return 0;
}

void unionOfArrays(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& result) {
    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        // Before pushing the current element check 2 conditions
        // if the result is empty, directly insert it
        // if the result vector is not empty, then compare the current element with the last added element to vector
        if (arr1[i] < arr2[j]) {
            if (result.size() == 0 || result.back() != arr1[i])
                result.push_back(arr1[i]);

            ++i;
        } else if (arr1[i] > arr2[j]) {
            if (result.size() == 0 || result.back() != arr2[j])
                result.push_back(arr2[j]);

            ++j;
        } else {
            if (result.size() == 0 || result.back() != arr1[i])
                result.push_back(arr1[i]);

            ++i;
            ++j;
        }
    }

    if (i < arr1.size()) {
        for (; i < arr1.size(); i++) {
            if (result.size() == 0 || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
        }
    }
    if (j < arr2.size()) {
        for (; j < arr2.size(); j++) {
            if (result.size() == 0 || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
        }
    }
}

void print(std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}
