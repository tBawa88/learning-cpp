#include <iostream>
#include <string>

void printBinary(int digit, std::string prefix = "") {
    if (digit == 0) {
        std::cout << prefix << std::endl;
        return;
    }

    printBinary(digit - 1, prefix + "0");
    printBinary(digit - 1, prefix + "1");
}

int main() {
    printBinary(3);
    return 0;
}

/**
 * SOLUTION:
 * Draw out this problem on paper, we notice that the problem is self repeating
 * printBinary(n) is just prinBinary(n-1) with a prefix of 0
 *                    and printBinary(n-1) with a prefix of 1
 * And our base case is when there is no digits to print, then we just print the prefix
 * Becuase at that moment, the "digit" string represents all the decisions we've made uptill that point
 *      due to recusion's exhaustive search property
 *
 * Also the reason why we're appending the prefix and not "pre-pending" it is we want to print all the function calls that came before me
 * Like for digit = 3, we want to print all the calls before 3, and append them with a 0 or 1 prefix
 * printBinary(0) = ""
 * printBinary(1) = 0
 *                  1
 * printBinary(2) = 00
 *                  01
 *                  10
 *                  11
 * printBinary(3) = 000
 *                  001
 *                  010
 *                  011
 *                  100
 *                  101
 *                  110
 *                  111
 *
 */
