#include <cstdio>
#include <cstring>
#include <stdexcept>

struct SimpleString {
   private:
    size_t max_size;  // size_t is just int, but used for sizes and return values of sizeof() or stdlib functions like std::vector.size()
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
        delete[] buffer;  // remeber to delete all dyncamicall allocated members of the class inside the destructor
    }
    /**
     * This pattern of allocating memory to the memeber inside constructor and releasing it inside destructor is called RAII (resource acquisition is initialization)
     * or CADRe(constructor allocated destructor releases)
     */
};
