#include <iostream>
#include <vector>

/**
 * Vectors are like arrays on steroids.
 * They can grow and shrink like a dynamic array and lot more extra functionality
 */

// using an iterator
void displayVector(const std::vector<int>& v) {
    std::vector<int>::const_iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// using auto keyword
void autoVector(const std::vector<int>& v) {
    // auto inferring the iterator
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// using range based for loop
void rangeVector(const std::vector<int>& v) {
    for (auto it : v) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    displayVector(v);
    autoVector(v);
    rangeVector(v);

    // initializes a vector of size 10, and all of it's elements are set to 69
    std::vector<int> v2(10, 69);
    displayVector(v2);

    // initialzing a vector using other sequences
    // to do this you have to provide a starting address, and an ending address
    int arr[] = {5, 6, 7, 8};
    size_t size = sizeof(arr) / sizeof(int);
    std::vector<int> vectorFromArray(arr, arr + size);

    // using other vectors
    std::vector<int> copyVector(v);  // using the copy constructor, created a new copy

    return 0;
}
