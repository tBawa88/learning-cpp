#include <cstdio>

int step_function(int x) {
    return x;
}

int main() {
    int n1{42};
    int result1 = step_function(n1);

    int n2{0};
    int result2 = step_function(n2);

    int n3{-234};
    int result3 = step_function(n3);

    printf("Result1 = %d\n", result1);
    printf("Result2 = %d\n", result2);
    printf("Result3 = %d\n", result3);

    return 0;
}
