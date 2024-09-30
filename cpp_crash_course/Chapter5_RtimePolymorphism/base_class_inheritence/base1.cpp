#include <cstdio>

/**
 * Since C++ does not have an interface keyword to create an interface which defines method signatures
 * We have to simulate it using Base class inheritence
 */

struct BaseClass {
    int the_answer() const { return 45; }
    const char* member = "goldyboi";

   private:
    const char* member2 = "joyboy";
};

struct DerivedClass : BaseClass {};

void baseClassMethod(BaseClass& b) {
    printf("This is base class instance\n");
}

void derivedClassMethod(DerivedClass& D) {
    printf("This is derived class instance\n");
}

int main() {
    BaseClass b;
    DerivedClass d;

    baseClassMethod(b);
    baseClassMethod(d);  // derived classes have an 'is a' relation with the base class. Every derived class is a base class

    derivedClassMethod(d);
    printf("Public member %s\n", d.member);
    // derivedClassMethod(b);       // this is a compiler error
}
