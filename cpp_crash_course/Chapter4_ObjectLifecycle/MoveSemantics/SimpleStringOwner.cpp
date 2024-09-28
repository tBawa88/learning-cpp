#include <cstdio>
#include <cstring>
#include <utility>

struct SimpleString {
    size_t max_capacity;
    char *buffer;
    unsigned int length;

    SimpleString(size_t size) : max_capacity{size}, length{0} {
        buffer = new char[size];
    }

    SimpleString(SimpleString &&other) noexcept
        : max_capacity{other.max_capacity}, buffer{other.buffer}, length{other.length} {
        other.buffer = nullptr;
        other.max_capacity = 0;
        other.length = 0;
    }

    SimpleString &operator=(SimpleString &&other) noexcept {
        if (this == &other) return *this;

        delete[] buffer;  // since this is rvalue assignment, and we're making the other.buffer as nullptr,
        // .. it's okay to directly copy address stored in buffer like this
        buffer = other.buffer;
        max_capacity = other.max_capacity;
        length = other.length;

        other.buffer = nullptr;
        other.length = 0;
        other.max_capacity = 0;

        return *this;
    }

    bool append_string(char *str) {
        if (std::strlen(str) + length + 1 > max_capacity) return false;

        std::strncpy(buffer + length, str, max_capacity - length);
        length += std::strlen(str);
        buffer[length] = '\0';
        return true;
    }

    void print() { printf("%s\n", buffer); }
};

struct StringOwner {
    SimpleString string;

    StringOwner(SimpleString &&str) : string{std::move(str)} {}
    /**
     * Why use std::move() here?
     * We're trying to move the str object into string object instead of copying it so we want to call the move constructor
     *  Think about it, rvalue and rvalue reference are 2diff things
     * When we use 'str' inside the function body, even though its a rvalue reference, but since it has a name (str), it will behave like a lvalue
     *
     */
};

int main() {
    SimpleString a{100};
    a.append_string("Cardiff");
    a.print();

    SimpleString b{50};
    b.append_string("Control Data");
    b.print();

    // moving a into b, using move assignment
    // first have to convert a from lvalue to rvalue
    b = std::move(a);
    b.print();
    // a.print();   // a is in moved-from state, cannot access it like this
    return 0;
}
