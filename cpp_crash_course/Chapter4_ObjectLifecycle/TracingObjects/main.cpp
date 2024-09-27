#include <cstdio>
#include <iostream>
#include <string>

struct Tracer {
    Tracer(std::string name) : name{name} {
        std::cout << "Constrcuted" << this->name << std::endl;
    }

    ~Tracer() { std::cout << "Destructed name" << name << std::endl; }

   private:
    const std::string name;
    // const int test;      == normal constant variable
    // const int * test_ptr;    == normal constant pointer
    // const int * const test_const;    == a constant pointer pointing to anohter constant value
    /**
     * The first const before char*, represents that the value pointed to by this pointer is a constant value
     * The second const after char* represents that the pointer itself is a constant pointer. Meaning once it's been initialized, it cannot be made to point to any other
     * address in the memory
     */
};

static Tracer t1{"Static tracer"};
thread_local static Tracer t2{"thread_local tracer"};  // don't need to use static with thread_local

int main() {
    printf("A\n");
    Tracer t3{"Automatic local variable"};
    printf("B\n");

    const auto* t4 = new Tracer{"Dynamically allocated tracer"};
    printf("C\n");
    delete t4;
    return 0;
}

/**
 * Since we did not explicitly delete the dynamically allocated object, we do not see it's destructor message
 * This means we've leaked the memory for that object.
 */
