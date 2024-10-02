#include <cstdio>
#include <utility>

/**
 * This is an implementation of a template class
 */

template <typename P>
struct SimpleUniquePointer {
    SimpleUniquePointer() = default;  // telling the compiler to generate a default impmlemenation of this constructor
    // if we don't provide default constructor, the compiler wont generate it and we won't be able to declare the object wihout instatiating it.
    // this will set the private member (pointer) to it's zero value which is nullptr in this case.

    SimpleUniquePointer(P* ptr) : pointer{ptr} {}

    ~SimpleUniquePointer() {
        if (pointer) delete pointer;  // deletes the underlying dynamically allocated object
    }

    // by using delete, we're telling the compiler to not create a default implementation of copy constructor and assigment
    // reason : the essence of unique pointers is that it is a sole owner of a dynamically allocated object
    // Meaning we cannot have this->pointer of 2 seperate classes point to the same object
    SimpleUniquePointer(const SimpleUniquePointer&) = delete;
    SimpleUniquePointer& operator=(SimpleUniquePointer&) = delete;

    // WE WANT MOVE SEMANTICS : it's okay to transfer the ownership of the pointed-to object but copying is prohibited
    SimpleUniquePointer(SimpleUniquePointer&& other) noexcept {
        pointer = other.pointer;
        other.pointer = nullptr;  // handoff, this is crucial otherwise the destructor of this moved-from object will destroy the pointed-to object
    }

    SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
        if (*this == other) return *this;
        if (pointer) delete pointer;
        pointer = other.pointer;
        other.pointer = nullptr;

        return *this;
    }

    P* get() { return pointer; }

   private:
    P* pointer;
};

struct Tracer {
    Tracer(const char* name) : name(name) {}
    ~Tracer() {
        printf("Tracer destroyed %s\n", name);
    }

   private:
    const char* name;
};

void consumer(SimpleUniquePointer<Tracer> consumer_ptr) {
    printf("(cons) consumer_ptr = 0x%p\n", consumer_ptr.get());  // returns the address of underlying tracer object
}

int main() {
    const char* name = "elijah";
    Tracer* trace = new Tracer{name};

    SimpleUniquePointer<Tracer> u_ptr{trace};
    printf("(main) unique_pointer = 0x%p\n", u_ptr.get());

    consumer(std::move(u_ptr));  // if moving is not used, it will create a copy of SimpleUniquePointer inside the consumer() and we don't want that

    printf("(main) unique_pointer = 0x%p\n", u_ptr.get());

    return 0;
}
