#include <iostream>

/**
 * Digital root of a function is defined as sum of all the digits inside that number
 * 12345 = 1 + 2 + 3 + 4 + 5 = 15
 */

int digitalRoot(int);
int main() {
    int n;
    std::cin >> n;
    std::cout << "Digital root of " << n << " = " << digitalRoot(n) << std::endl;
    return 0;
}

int digitalRoot(int n) {
    if (n / 10 == 0)
        return n;
    else
        return (n % 10) + digitalRoot(n / 10);
}
