#include <cstddef>
#include <cstdio>

/**
 * size_t is an unsgined data type in C/C++ which is used to represent size of objects in memeory
 *
 */

int main() {
    size_t size_c = sizeof(char);
    size_t size_s = sizeof(short);
    size_t size_i = sizeof(int);
    size_t size_d = sizeof(double);

    printf("char: %zd\n", size_c);
    printf("short: %zd\n", size_s);
    printf("int: %zd\t\n", size_i);
    printf("double: %zd\t\n", size_d);
}
