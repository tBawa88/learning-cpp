// using euclid's division lemma
// any number can be represented in the form of it's divisor, quotient and the remainder
// a = bq + r;
// b is the divisor
// q is the quotient
// r is the remainder, 0<= r < b

int gcd_helper(int x, int y);

int gcd(int x, int y) {
    if (x > y)
        return gcd_helper(x, y);
    else
        return gcd_helper(y, x);
}

int gcd_helper(int x, int y) {
    int r = x % y;
    if (r == 0)
        return y;
    return gcd_helper(y, r);
}
