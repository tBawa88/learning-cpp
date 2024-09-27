#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
   private:
    size_t max_size;
    size_t length;
    char *buffer;

   public:
    SimpleString(size_t size) : max_size(size), length{} {
        if (max_size == 0) {
            throw std::runtime_error{"Size must be more than 0"};
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }
    ~SimpleString() {
        delete[] buffer;
    }

    void print(const char *tag) const {
        printf("%s : %s\n", tag, buffer);
    }

    // appends a new line to the internal buffer string of this class
    bool append_line(char *str) {
        const auto str_len = strlen(str);
        if (str_len + length + 2 > max_size) return false;

        // strncpy(dest. address, source address, number of bytes to copy from source to dest)
        // max_size - length ensures that it only copies according to the remaining capacity of the buffer, preventing it going out of bounds
        strncpy(buffer + length, str, max_size - length);
        length += str_len;  // increase the length
        buffer[length++] = '\n';  // add a newline character in the end
        buffer[length] = 0;  // end it with a null character
        return true;
    }
};
/**
 * strncpy() needs to be used very carefully. if you forget to make sure that the source string is null-terminated, it will not know how many bytes to copy or when to stop
 * Also the target string must have enough capacity, keeping in mind that it will have a null character in the end. If there is not enough space, stncpy() will not be able to
 * insert a null character in the end, and using a non null-terminated string causes undefined behaviour
 */

int main() {
    SimpleString s{20};
    s.print("starting");

    s.append_line("the");
    s.print("append_line1");

    s.append_line("name");
    s.print("append_line2");

    s.append_line("primeagen");
    s.print("final");

    return 0;
}
