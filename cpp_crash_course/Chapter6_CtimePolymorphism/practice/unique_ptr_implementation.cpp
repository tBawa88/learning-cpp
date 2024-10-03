#include <cstdio>
#include <cstring>
#include <utility>
/**
 * A unique pointer always points to a single underlying object which is dynamically allocated
 * A unique pointer helps us implement RAII and we don't have to worry about manually deleting the object
 * 2 unique pointers never point to the same object, hence their implementation does not have Copy semantics and only move semantics
 *
 */

struct SimpleString {
    SimpleString() = default;
    SimpleString(size_t max_cap) : max_capacity{max_cap}, length{} {
        buffer = new char[max_cap];
    }
    ~SimpleString() {
        printf("deleting string\n");
        delete[] buffer;  // RAII, release the resources allocated inside the constructor
    }

    // let's implement the semantics now
    // Copy semantics using lvalues
    // since copy constructor, just allocate the memory directly without worrying about
    SimpleString(SimpleString& other) noexcept
        : length{other.length},
          max_capacity{other.max_capacity} {
        buffer = new char[max_capacity];
        std::strncpy(buffer, other.buffer, max_capacity);
    }

    // copy assignment operator, here we need to worry about if there is something already existing inside the buffer OR is it a self assignment
    SimpleString& operator=(SimpleString& other) noexcept {
        if (this == &other) return *this;
        if (buffer) delete[] buffer;
        length = other.length;
        max_capacity = other.max_capacity;
        buffer = new char[max_capacity];
        std::strncpy(buffer, other.buffer, max_capacity);
        return *this;
    }

    // move constructor
    SimpleString(SimpleString&& other) noexcept
        : length{other.length},
          max_capacity{other.max_capacity},
          buffer{other.buffer} {
        other.buffer = nullptr;
        other.length = 0;
        other.max_capacity = 0;
    }

    // move assignment operator
    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this == &other) return *this;
        if (buffer) delete[] buffer;
        length = other.length;
        max_capacity = max_capacity;
        buffer = other.buffer;
        other.buffer = nullptr;
        other.length = 0;
        other.max_capacity = 0;
        return *this;
    }

    bool appendString(char* str) {
        if (length + std::strlen(str) + 1 > max_capacity) return false;

        std::strncpy(buffer + length, str, max_capacity - length);
        length += std::strlen(str);
        buffer[length] = '\0';
        return true;
    }

    void print() {
        if (buffer)
            printf("%s\n", this->buffer);
    }

   private:
    unsigned int length;
    char* buffer = nullptr;
    size_t max_capacity;
};

template <typename T>
struct unique {
    unique() = default;
    ~unique() {
        if (pointer) delete pointer;
    }

    unique(T* object) {
        pointer = object;
    }

    // telling the compiler to not build a default implementation of copy semantics
    unique(unique& u) = delete;
    unique& operator=(unique& u) = delete;

    // building move semantics
    unique(unique&& u) noexcept : pointer{u.pointer} {
        u.pointer = nullptr;
    }
    // always check for same object assignment in move assignment overload..... holly broooooo
    unique& operator=(unique&& u) {
        if (this == &u) return *this;
        pointer = u.pointer;
        u.pointer = nullptr;
        return *this;
    }

    T* get() { return this->pointer; }

   private:
    T* pointer = nullptr;
};

int main() {
    // testing if we really don't have to worry about manually deleting the dynamic object
    SimpleString* s = new SimpleString{200};
    unique<SimpleString> uptr{s};
    s->appendString("testing");
    s->print();
    uptr.get()->print();
    // no delete statement for SimpleString *s, but since uptr is a local object, when it eventually gets destructed, it will also destruct the pointer it's pointing to
    return 0;
}
