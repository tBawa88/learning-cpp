#include <iostream>

/**
 * GCD of x and y  is the largest integer that divides both of these 2 evenly
 * ALGO:
 *  1. if x is evenly divisible by y ; y is the gcd
 *  2. otherwise gcd(x,y) is equal to gcd(y, x%y);
 */

int GCD(int x, int y);
int gcdHelper(int x, int y);

int main() {
    int x, y;
    std::cin >> x >> y;
    int ans = GCD(x, y);

    std::cout << "GCD of " << x << " & " << y << " = " << ans << std::endl;
    return 0;
}

int GCD(int x, int y) {
    return x > y ? gcdHelper(x, y) : gcdHelper(y, x);
}

int gcdHelper(int x, int y) {
    if (x % y == 0)
        return y;

    int rem = x % y;
    return gcdHelper(y, rem);
}
