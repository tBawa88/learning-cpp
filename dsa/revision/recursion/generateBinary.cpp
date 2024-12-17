#include <iostream>
#include <string>
/**
 * Given an integer N representing total bits, generate all possible numbers that can be represented using those bits
 *
 * eg: GenerateBinary(1)  -> 0 1
 *      generateBinary(2) -> 00 01 10 11
 *      generateBinary(3) -> 000 001 010 011 100 101 110 111
 */

void GenerateBinary(int n);
void generateBinaryHelper(int n, std::string binString = "");

void GenerateBinary(int n) {
    generateBinaryHelper(n);
}

void generateBinaryHelper(int n, std::string binString) {
    if (n == 0) {
        std::cout << binString << std::endl;
    } else {
        generateBinaryHelper(n - 1, binString + '0');
        generateBinaryHelper(n - 1, binString + '1');
    }
}
