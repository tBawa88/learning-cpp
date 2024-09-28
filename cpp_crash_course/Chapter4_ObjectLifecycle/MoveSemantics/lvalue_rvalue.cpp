#include <cstdio>

void ref_type(int &x) {
    std::printf("lvalue refrence %d\n", x);
}

// same function, but using rvalue reference
void ref_type(int &&x) {
    printf("rvalue reference %d\n", x);
}

// based on how we're passing the value, the compiler will automatically call the correct version
int main() {
    auto x{1};
    auto y{1};

    ref_type(x);  // argument has a name = lvalue
    ref_type(100);  // argument is literal, no name = rvalue

    ref_type(x + y);  // the expression evaluates to 2, therefore no name = rvalue

    return 0;
}
