#include <cstdio>
/**
 *
 * They look like copy constructors, but they take rvalue refrences, whereas copy constructors take lvalue refrences
 */

struct SimpleString {
    size_t max_length;
    char *buffer;
    unsigned int length;

    // move constructor                                              //directly putting copying the buffer
    SimpleString(SimpleString &&other) noexcept
        : max_length(other.max_length),
          buffer(other.buffer),
          length(other.length) {
        other.length = 0;
        other.max_length = 0;
        other.buffer = nullptr;
    }
};

/**
 * You might think that since it's an rvalue, why do we even need to erase the value of 'other'
 * Consider what would happen when other is destructed (since it's a local variable and soon as constructor exits the call stack, it'll be destrcuted)
 * The buffer of current object will also be freed.
 *
 * Executing this is lot less expensive than copy constructor
 *
 */
