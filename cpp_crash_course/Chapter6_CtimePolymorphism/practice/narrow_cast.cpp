#include <cstdio>
#include <iostream>
#include <stdexcept>

template <typename To, typename From>
To narrow_cast(From val) {
    const auto converted = static_cast<To>(val);
    const auto backwards = static_cast<From>(converted);
    if (val != backwards) throw std::runtime_error{"narrowing occured"};

    return converted;
}

int main() {
    int value{345236723};

    try {
        auto val = narrow_cast<short>(value);
        printf("Value converted no issue %d\n", val);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
