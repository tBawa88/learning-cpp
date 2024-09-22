#include <cstdio>
#include <string>

/**
 * Ther are 2 types of strings available in C++
 * C - style strings, that end with a 0 bit called null character
 * String literals - "abc" enclosed in double quotes
 */

int main() {
    // a C-style string is an array of characters
    char name[] = "Tejas";
    std::string address = "Punjab, India";

    // iterating over strings
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%c", name[i]);
    }
    printf("\n");

    // another way using char pointer
    for (char *c = name; *c != '\0'; c++) {
        printf("%c", *c);  // using pointer math, init a pointer to the first element, and then increment it
    }

    printf("\n");
    // string literals from C++ <string> library have length method on 'em
    for (int i = 0; i < address.length(); i++) {
        printf("%c", address[i]);
    }
}
