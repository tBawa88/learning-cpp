#include <cstdio>
#include <utility>

void ref_type(int &x) {
    std::printf("lvalue refrence %d\n", x);
}

// same function, but using rvalue reference
void ref_type(int &&x) {
    printf("rvalue reference %d\n", x);
}

int main() {
    auto x{1};
    auto y{1};

    ref_type(std::move(x));  // the std::move() function converts a lvalue to rvalue reference

    return 0;
}
