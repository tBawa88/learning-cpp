#include <iostream>

/**
 * Write a function Combinations(int n, int k) which finds the result without calling Factorial function
 * Use the property of pascals triangle. Which tells us that when we arrange combinations in a triangle,
 * we find that the top and all outer elements are one, and the inner elements are sum of 2 elements above them
 */

int Combinations(int n, int k);
int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << n << " choose " << k << " = " << Combinations(n, k) << std::endl;

    return 0;
}

int Combinations(int n, int k) {
    if (n == 0 || k == n || k == 0)
        return 1;

    return Combinations(n - 1, k - 1) + Combinations(n - 1, k);
}
