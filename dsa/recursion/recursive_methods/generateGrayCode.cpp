#include <iostream>
#include <string>

/**
 *  Gray code makes sure that no 2 adjacent integers differ more than 1 bit in their representation
 *
 *  Graycode(1) = 0
 *                1
 *  GrayCode(2) = 00
 *                01
 *                11
 *                10
 *
 *  GrayCode(3) = 000 - 0
 *                001 - 1
 *                011 - 2
 *                010 - 3
 *                110 - 4
 *                111 - 5
 *                101 - 6
 *                100 - 7
 *
 * The pattern is GrayBit(n) = 0 + Graybit(n-1)
 *                             1 + ReverseGrayBit(n-1)
 */

void GrenerateGrayCode(int n);
void grayCode(int n, std::string prefix);
void reverseGrayCode(int n, std::string prefix);

int main(void) {
    GrenerateGrayCode(3);
    return 0;
}

void GrenerateGrayCode(int n) {
    grayCode(n - 1, "0");
    reverseGrayCode(n - 1, "1");
}

void grayCode(int n, std::string prefix) {
    if (n == 0) {
        std::cout << prefix << std::endl;
    } else {
        reverseGrayCode(n - 1, prefix + "0");
        reverseGrayCode(n - 1, prefix + "1");
    }
}

void reverseGrayCode(int n, std::string prefix) {
    if (n == 0) {
        std::cout << prefix << std::endl;
    } else {
        reverseGrayCode(n - 1, prefix + "1");
        reverseGrayCode(n - 1, prefix + "0");
    }
}
