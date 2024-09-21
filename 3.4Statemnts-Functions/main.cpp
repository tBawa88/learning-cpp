#include <iostream>

int add(int a, int b) { return a + b; }

int main() {

    int num1 = 20;  // copy initialization, this allows for implicit type conversion int num1 = 20.4 will be converted into 20
    int num2{10};  // brace initialization/list initlization, doesn't allow conversion, raises a warning, is a more safer way of initializing objects and variables


    std::cout << add(num1, num2) << std::endl;
    return 1;
}
