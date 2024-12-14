int power(int n, int pow) {
    if (pow == 0)
        return 1;
    else {
        return n * power(n, pow - 1);
    }
}
