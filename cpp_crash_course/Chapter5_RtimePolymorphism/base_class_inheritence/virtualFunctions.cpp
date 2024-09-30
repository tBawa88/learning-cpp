#include <cstdio>

struct Bird {
    virtual void fly() = 0;  // Pure virtual functions donot have implementation inside the Base class
};

/**
 * Any class that has a pure virtual function becomes a Pure Virtual class. It then exists only to enable interface inheritence
 */

struct Peakcock : Bird {
    void fly() override {
        printf("The bird is flying\n");
    }
};

int main() {
    Peakcock p;
    p.fly();
    return 0;
}
