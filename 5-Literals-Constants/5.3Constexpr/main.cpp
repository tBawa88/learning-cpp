#include <iostream>

// 'constexpr' defines constant expressions that are evalutated at compile time rather than runtime
// A constexpr 'function' must produce results that can be determined at compiler time
// A constexpr 'variable' mus be initialized with a constexpr

// they're mostly used for compile time constants like 'Template arguments' or 'Array sizes'

// constexpr function
constexpr int getSize() { return 10; }

int main() {
    constexpr int size = getSize();

    std::cout << "The constexpr value is = " << size << std::endl;

    int arr[size];
    for (int i = 0; i < size; i++) {
        *(arr + i) = i;  // using poitner arithmetic
    }

    return 0;
}

/*
    Difference between a const and constexpr

    1. const can be evaluated at runtime
        const int someValue = calculate(20);   // this value is not known at compile time

    2. constexpr value must always be known at compile time
        constexpr int compile_time_constant = 100;
*/
