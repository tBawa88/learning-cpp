#include <cstdio>

struct Base {
    virtual ~Base() {}
};

/**
 * Side note: This is the basic difference between structs and classes in c++
 * In a class,the default access specifier of every member function is private, and the default inheritence is also private
 * But in a struct, every member is public by default
 */
class Derived : public Base {
   public:
    Derived() { printf("Derived() invoked\n"); }
    ~Derived() { printf("~Derived() invoked\n"); }
};

/**
 * If the base class does not have a virtual destructor, then it's resources won't be released
 */

int main() {
    printf("Constructing Base class\n");
    Base *b{new Derived{}};
    printf("Deleting base class\n");

    delete b;
    return 0;
}
