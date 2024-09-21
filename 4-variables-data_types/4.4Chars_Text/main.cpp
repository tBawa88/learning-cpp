#include <iostream>

int main () {
    // characters in c++ occupy 1 byte (8 bits), meaning there are 256 possible combinations that we could represent in a char
    // each possible bit number is mapped to some characters
    // character codes from 0 to 127 are mapped to unique characters that are called ASCII characters

    // we can either assign a valid ASCII code to a char type, and the compiler will store the character that is mapped to that code
    char a {65};    // ASCII code for char A
    std::cout << a << std::endl;

    char c {'C'};   // ASCII code of 67
    std::cout << a - c << std::endl;    // prints -2
    std::cout << sizeof(a) << " byte" << std::endl;

    return 0;

}
