
int fibonacci(int n);
int fibonacci_helper(int n, int t1, int t2);

int fibonacci(int n) {
    return fibonacci_helper(n, 0, 1);
}

int fibonacci_helper(int n, int t1, int t2) {
    if (n == 1)
        return t1;
    if (n == 2)
        return t2;

    return fibonacci_helper(n - 1, t2, t1 + t2);
}
