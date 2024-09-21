#include <iostream>

int main()
{
    std::cout << "Hello world" << std::endl;
    printf("We can also write C code inside C++ code \t Like this printf() function \n");
    return 0;
}

/**
 * Modify the tasks.json file to make sure that the g++ compiler uses c++20 standard to compile your code
 *  ctrl + shift + p , then type configure default buid task and then add -std=c++20 flag in the args array
 *
 * Modify the c_cpp_properties.json file to get the intellisense support for c++20 syntax
 * ctrl + shift + p , then type C/C++ edit configurations UI
 *
 * TO build your project using this default task, press 'Ctrl + Shift + B'
 *
 */
