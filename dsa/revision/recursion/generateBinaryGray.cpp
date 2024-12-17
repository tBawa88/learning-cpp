#include <iostream>
#include <string>
/**
 * Gray code differs froim binary such that the adjacent numbers only differ by 1 bit
 */

void GenerateGrayCode(int n);
void binaryHelper(int n, std::string binString, bool isReverse);

void GenerateGrayCode(int n) {
    binaryHelper(n - 1, "0", false);
    binaryHelper(n - 1, "1", true);
}

void binaryHelper(int n, std::string binString, bool isReverse) {
    if (n == 0) {
        std::cout << binString << std::endl;
    } else {
        if (!isReverse) {
            binaryHelper(n - 1, binString + '0', false);
            binaryHelper(n - 1, binString + '1', false);
        } else {
            binaryHelper(n - 1, binString + '1', true);
            binaryHelper(n - 1, binString + '0', true);
        }
    }
}
