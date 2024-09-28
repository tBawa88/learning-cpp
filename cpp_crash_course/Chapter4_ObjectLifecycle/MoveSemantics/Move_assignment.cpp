#include <iostream>
/**
 *
 *
 * Just like copy assignment operator, we can overload the assignment operator to accept rvalues and execute the move operation
 */

struct SimpleString {
    size_t max_length;
    char *buffer;
    unsigned int length;

    SimpleString &operator=(SimpleString &&other) noexcept {
        if (this == &other) return *this;

        // copy data
        buffer = other.buffer;
        length = other.length;
        max_length = other.max_length;

        // make other nil
        other.length = 0;
        other.max_length = 0;
        other.buffer = nullptr;

        return *this;
    }
};
