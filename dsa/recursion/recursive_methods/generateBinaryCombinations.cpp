#include <iostream>
#include <string>
/**
 * Generate all possible binary representations when given 'n' bits
 *
 * n = 1 ; output => 0 1
 * n = 2 ; output => 00 01 10 11
 * n = 3; output =>  000 001 010 011
 *                   100 101 110 111
 */

void GenerateBinary(int& n);
void printCombinations(int n, std::string prefix = "");

int main() {
    int n;
    std::cin >> n;
    GenerateBinary(n);
    return 0;
}

void GenerateBinary(int& n) {
    printCombinations(n);
}
void printCombinations(int n, std::string prefix) {
    if (n == 0) {
        std::cout << prefix << std::endl;
    } else {
        printCombinations(n - 1, prefix + '0');
        printCombinations(n - 1, prefix + '1');
    }
}
