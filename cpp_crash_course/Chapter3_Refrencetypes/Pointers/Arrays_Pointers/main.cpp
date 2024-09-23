#include <cstdio>

struct College {
    char name[256];
};

void printCollegeNames(College* collegeList, int len) {
    for (int i = 0; i < len; i++) {
        printf("College %d = %s\n", i + 1, (collegeList + i)->name);
    }
    // 'name' itself is an array, therfore when we pass name for the %s string specifier, it's another example of pointer decay
}

int main() {
    // an array of typpe
    College college_list[] = {"Harvard", "MIT", "UCLA"};

    // the name of the array is a pointer. It stores the base address (addr of 0th element)
    // When we pass the name of the array as pointer, it's called Pointer decay

    /*
     This is common way of passing arrays to function.
     1st argument = pointer to the array
     2nd argument = length of the array
    */
    printCollegeNames(college_list, sizeof(college_list) / sizeof(College));

    char c[] = "abcde";
    /**
     * 'c' has length of 6, 6th one being the \0 character
     * Size of an array is decied at compile time and is fixed, therefore we cannot access an outof bounds memory like this
     * meaning c[7] = 'x'; is very dangerous and could fu*k with the system
     */
}
