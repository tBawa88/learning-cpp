#include <cstdio>

int main() {
    int age{10};
    printf("age = %d\n", age);

    int *age_addr = &age;
    // prints a hex based memory address
    printf("&age = %p\n", age_addr);

    *age_addr = 30;
    // dereferencing a pointer is same as using the underlying object directly
    printf("age = %d\n", age);

    // double pointer, stores the memory address of the pointer variable
    int **age_dptr = &age_addr;
    printf("age = %d\n", **age_dptr);  // to get to the underlying value, must use double asterisk
    // **age_dptr = the first asterisk gives direct access to the underlying pointer (it's address value)
    // the second asterisk gives access to the value stored at that address

    // changing mem address of age_addr using the double pointer
    int age2 = 40;
    *age_dptr = &age2;  // *age_dptr gives access to mem address value of age_addr, we overwrote the address value with this new address value
    printf("age1 = %d\n", age);  // 30
    printf("age2 = %d\n", *age_addr);  // 40

    // if we make changes to age_addr, they will not affect age2 instead of 'age'
}
