#include <cstdio>

template <typename X>
X myTemplateFunc(X& val1, X& val2) {
    return val1 + val2;
}

/**
 * Instantiating template functions
 */

/**
 * Type saftey in C++ templates
 */
template <typename T>
T square(T value) {
    return value * value;
}

int main() {
    int a = 100, b = 200;
    int result = myTemplateFunc<int>(a, b);
    printf("%d\n", result);

    char c{'0'};
    auto sq = square(&c);  // can't multiply pointer type, program fails to compile
    printf("%c\n", sq);
    return 0;
}
