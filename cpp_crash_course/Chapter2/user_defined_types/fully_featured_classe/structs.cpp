#include <cstdio>

struct Dumbell {
    int weight;

    void setWeight(int w) { weight = w; }
    int getWeight() { return weight; }
};

/**
 * structs and classes are very similar to each other.
 * Key differences are
 *  - in struct, all members are 'public' by default
 *  - in a class, all memebers are 'private' by default
 *
 * In C++, struct is essentially a class, but with public modifier by default
 * it has constructors and destructors just like a class does.
 * They can inherit data from other structs just like classes can
 *
 */

int main() {
    Dumbell d;
    d.setWeight(50);

    printf("Weight of the dumbell is = %d\n", d.getWeight());

    return 0;
}
