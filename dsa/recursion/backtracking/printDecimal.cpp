#include <iostream>
#include <string>

/**
 * Write a recursive function which prints all the base 10 (decimal) numbers with given number of digits
 * print(0) = ""
 * print(1) = 0 1 2 3 4 5 6 7 8 9
 * print(2) = 00 01 02 03 04 .. 99
 * print(3) = 000 001 002 003 .. 999
 *
 * SOLUTION:
 * We can solve this by using the same "prefix" approach used in printBinary1.cpp
 * If you notice, print(1) is just print(0) but with 0-9 prefixes added to the result
 * print(2) is just print(1) printed 10 times with 0-9  prefixes added to the result
 * print(3) is just print(2) printed 10 times with 0-9 prefixes added to each iteration
 */

void printDecimal(int digit, std::string prefix = "");

int main() {
    printDecimal(3);
}

void printDecimal(int digit, std::string prefix) {
    if (digit == 0) {
        std::cout << prefix << std::endl;
        return;
    }

    for (int i = 0; i <= 9; i++)
        printDecimal(digit - 1, prefix + std::to_string(i));

    // printDecimal(digit - 1, prefix + "0");
    // printDecimal(digit - 1, prefix + "1");
    // printDecimal(digit - 1, prefix + "2");
    // printDecimal(digit - 1, prefix + "3");
    // printDecimal(digit - 1, prefix + "4");
    // printDecimal(digit - 1, prefix + "5");
    // printDecimal(digit - 1, prefix + "6");
    // printDecimal(digit - 1, prefix + "7");
    // printDecimal(digit - 1, prefix + "8");
    // printDecimal(digit - 1, prefix + "9");
}
