#include <concepts>
#include <cstdio>
#include <vector>
// let's say we have this template we want to create
template <typename T>
T mean(T* values, size_t length) {
    T result{};  // type T must be constructible like this

    for (size_t i{}; i < length; i++) {
        result += values[i];  // type T must support += operator
    }
    return result / length;  // type T must support / operators
}

// looking at these requirement, let's build a custom conecpt using require
template <typename T>
concept Averageable = std::is_default_constructible_v<T> && requires(T a, T b) {
    { a += b } -> std::same_as<T>;
    { a / size_t{1} } -> std::same_as<T>;
};

// std::is_default_constructible_v<T> is a built in concept, like many others which can be used
// A type must pass all the checks to qualify as this type

template <Averageable A>
A Mean(const std::vector<A>& v) {
    A sum{};
    for (const A& elem : v) {
        sum += elem;
    }
    return sum / v.size();
}

int main() {
    std::vector<int> v = {1, 3, 4, 5};
    // auto value1 = Mean(v);
}
