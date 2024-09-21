#include <iostream>

int main() {
    auto var1{12};
    auto var2{23.34};
    auto var3{14.0f};
    auto var4{15.9l};
    auto var5{'a'};

    // integer modifier suffixes
    auto var6{123u};  // unsigned int
    auto var7{23525ll};  // long long

    std::cout << sizeof(var7) << std::endl;  // prints 8 (4 + 4 bytes)

    // NOTE : once the type has been 'auto' infered by the compiler, you cannot assign a diffferent type to the variable
    // va1 = "hello";

    return 0;
}
