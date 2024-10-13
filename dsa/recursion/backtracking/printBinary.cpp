#include <iostream>

/**
 * Write a recursive function called printBinary(int), which takes in an integer and prints it's binary form
 * printBinary(43) outputs 101011
 *
 *
 */
void printBinary(int);

int main() {
    printBinary(32);
    std::cout << std::endl;
    return 0;
}

/**
 * Binary of any number can be represented as [Binary of number / 2] + [Binary of number % 2]
 * And this is exactly our recursive calls are saying
 */
void printBinary(int n) {
    if (n < 2) {  // base case
        std::cout << n;  // 0 and 1 just print them
    } else {  // recursive call
        int lastDigit = n % 2;  // base 2 since it's binary, the result will be either 1 or 0
        int restOfDigits = n / 2;
        printBinary(restOfDigits);
        printBinary(lastDigit);  // this call will always go into 'if'
    }
}

/**
 *  43 =>   last = 1 ( so print 1)
 *          rest = 21 (call func(21))
 *  21 =>   last = 1 (print 1)
 *          rest = 10 (call func(10))
 *  10 =>   last = 0 (print 0)
 *          rest = 5 (call func(5))
 *  5 =>    last = 1 (print 1)
 *          rest = 2 (call func(2))
 *  2 =>    last = 0 (print 0)
 *          rest = 1 (call func(1))
 * 1 =>     basecondition => print 1
 *
 * Ouput(from the top) = 110101 (which is reverse of what we want)
 * Therefore we have to print the last digit on returning time
 *
 */
