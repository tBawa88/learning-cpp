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
        printf("Deleting internal buffer \n");
        delete[] buffer;
    }

    void print(const char *tag) const {
        printf("%s : %s\n", tag, buffer);
    }

    // appends a new line to the internal buffer string of this class
    bool append_line(char *str) {
        const auto str_len = strlen(str);
        if (str_len + length + 2 > max_size) return false;

        strncpy(buffer + length, str, max_size - length);
        length += str_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }
};

struct SimpleStringOwner {
   private:
    SimpleString string;

   public:
    /**
     * All memebers of the SimpleString object will be initialized "before" SimpleStringOwner's constructor is called
     */
    SimpleStringOwner(char *x) : string{10} {
        if (!string.append_line(x)) {
            throw std::runtime_error{"Not enough memory available on the string"};
        }
        string.print("Constructed ");
    }

    /**
     * Destructors work the oppsite way, All memebers "after" object's destructors is invoked
     */
    ~SimpleStringOwner() {
        string.print("About to destroy ");
    }
};

int main() {
    SimpleStringOwner s{"owner"};
    printf("owner is alive\n");

    return 0;
}
