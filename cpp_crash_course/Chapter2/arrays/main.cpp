#include <cstdio>

int main() {
    // type varname []
    long arr[] = {1, 3, 4, 5, 6, 7, 8, 8};

    // finding number of elements in array
    size_t arrSize = sizeof(arr) / sizeof(long);

    // iterating over the array using for loops
    for (int i = 0; i < arrSize; i++) {
        printf("arr[%d] = %ld\n", i, arr[i]);
    }

    // iterating over array using "range based for loops"
    for (long elem : arr) {
        printf("%ld\t ", elem);
    }
}
