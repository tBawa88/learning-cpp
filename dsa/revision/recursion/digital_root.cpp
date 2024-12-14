#include <stdio.h>

int digitalRoot(int n);
int digitSum(int n);

int digitalRoot(int n) {
    int s = digitSum(n);
    if (s < 10)
        return s;
    return digitalRoot(s);
}

int digitSum(int n) {
    if (n == 0)
        return 0;

    return (n % 10) + digitSum(n / 10);
}
