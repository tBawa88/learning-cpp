#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
   private:
    size_t max_size;
    char *buffer;
    int length;

   public:
    SimpleString() : max_size{100}, length{} {
        buffer = new char[max_size];
    }

    SimpleString(size_t size) : max_size(size), length{} {
        buffer = new char[max_size];
    }

    ~SimpleString() {
        delete[] buffer;
    }

    // overloading the copy assignment operator for this class' objects
    //  the reason for getting a reference is so that we don't make a local copy while calling this function
    SimpleString &operator=(const SimpleString &other) {
        if (&other == this) return *this;  // comparing memory addresses of other and this object. if it's the same, simple return *this (defrefrenced value of this)

        // implementing a clean hand-off
        length = other.length;
        max_size = other.max_size;

        const auto new_buffer = new char[max_size];
        delete[] buffer;  // delete the buffer, possible could contain pre-exisiting data
        buffer = new_buffer;
        std::strncpy(buffer, other.buffer, max_size);

        return *this;
    }

    bool append_string(char *str) {
        const auto str_len = strlen(str);
        if (str_len + length + 1 > max_size) return false;

        std::strncpy(buffer + length, str, max_size - length);
        length += str_len;
        buffer[length] = '\0';
        return true;
    }
    void print() {
        if (length == 0)
            printf("Empty string\n");
        else
            printf("%s\n", buffer);
    }
};

int main() {
    SimpleString s1{200};
    s1.append_string("Hello world");
    s1.print();

    SimpleString s2;
    s2.print();

    // copying data from s1 to s2 using the overloaded copy assignment operator
    s2 = s1;  // this might look like a normal use of operator, but it's actually a function call
    s2.print();

    // proving that the copies are independent
    s1.append_string("changed");
    s1.print();
    s2.print();
    return 0;
}
