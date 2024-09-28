#include <cstdio>
#include <cstring>
#include <utility>
/**
 * This program is combining copy constructor and assignment, move constructor and assignment inside one final program
 * In future, if your class has resources like netoworks, files, printers etc, implement a copy/move semantic like this
 */

struct SimpleString {
    SimpleString(size_t capacity) : max_capacity{capacity}, length{} {
        buffer = new char[max_capacity];
    }
    ~SimpleString() {
        delete[] buffer;
    }

    // copy semantics
    SimpleString(SimpleString& other)
        : max_capacity(other.max_capacity),
          length(other.length),
          buffer{new char[other.max_capacity]} {
        std::strncpy(buffer, other.buffer, max_capacity);
    }

    SimpleString& operator=(SimpleString& other) {
        if (this == &other) return *this;
        delete[] buffer;
        // deleting previous buffer, and elements of other buffer into this buffer
        buffer = new char[other.max_capacity];
        std::strncpy(buffer, other.buffer, max_capacity);
        max_capacity = other.max_capacity;
        length = other.length;
        return *this;
    }

    // move semantics
    SimpleString(SimpleString&& other) noexcept
        : max_capacity{other.max_capacity}, buffer{other.buffer}, length{other.length} {
        other.buffer = nullptr;
        other.length = 0;
        other.max_capacity = 0;
    }

    SimpleString& operator=(SimpleString&& other) {
        if (this == &other) return *this;
        delete[] buffer;  // free the old memory
        buffer = other.buffer;  // assign other's base addr to this buffer
        max_capacity = other.max_capacity;
        length = other.length;

        other.buffer = nullptr;
        other.length = 0;
        other.max_capacity = 0;
        return *this;
    }

    bool append(char* str) {
        if (max_capacity < std::strlen(str) + length + 1) return false;

        std::strncpy(buffer + length, str, max_capacity - length);
        length += std::strlen(str);
        buffer[length] = '\0';
        return true;
    }
    void print() { printf("%s\n", this->buffer); }

   private:
    size_t max_capacity;
    char* buffer;
    unsigned int length;
};

struct StringOwner {
   private:
    SimpleString string;

   public:
    StringOwner(SimpleString&& s) : string{std::move(s)} {}
};
