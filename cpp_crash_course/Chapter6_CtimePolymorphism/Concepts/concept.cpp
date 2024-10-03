#include <concepts>
#include <cstdio>
#include <iostream>

// will only accept integeral types (chars, ints, floats, bools etc)
template <std::integral T>
T square(T val) { return val * val; }

// Defining a Concept that supports equality operation
template <typename T>
concept EqualityComparable = requires(T a, T b) {
    { a == b } -> std::convertible_to<bool>;
};

// Creating a function that requires this concept
template <EqualityComparable T>
bool comparable(const T& a, const T& b) {
    return a == b;
}

int main() {
    auto val = square('c');
    printf("value = %d\n", val);

    int x{20};
    int y{22};
    auto result = comparable(x, y);
    std::cout << x << " & " << y << " are " << result << std::endl;
}
