#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
   private:
    size_t const max_size;
    char *buffer;
    int length;

   public:
    SimpleString(size_t size) : max_size(size), length{} {
        buffer = new char[max_size];
    }

    //  This is a copy constructor , notice we're making the argument as a constant since we don't need to
    SimpleString(SimpleString const &other) : max_size(other.max_size), length(other.length), buffer(new char[other.max_size]) {
        std::strncpy(buffer, other.buffer, max_size);
    }

    ~SimpleString() {
        delete[] buffer;
    }

    bool append_string(char *str) {
        const auto str_len = strlen(str);
        if (str_len + length + 2 > max_size) return false;

        std::strncpy(buffer + length, str, max_size - length);
        length += str_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
    void print() {
        if (length == 0)
            printf("Empty string");
        else
            printf("%s\n", buffer);
    }
};

int main() {
    SimpleString s1{200};
    s1.append_string("Hello world");
    s1.print();

    SimpleString s2{s1};  // this will call the copy constructor
    s2.print();

    return 0;
}
