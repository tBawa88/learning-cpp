#include <iostream>
#include <iomanip>

// Braced initialization


int main () {
    double num1 {1234.34599};
    double num2 {1234345e-3};       // this is same as num1, 1234.345 = 1234345 x 10 ^-3

    std::cout << std::setprecision(9);  // without this, the default precision for floating point numbers is 6 significant digits
    // those 6 digits could be before the point or after it doesn't matter
    // therefore we need to set the precision while displaying floating point numbers
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    return 0;
}
