#include <cstdio>

struct Dumbell {
   private:  // Just like a Class, you can make data members private and public
    int weight;

   public:
    Dumbell() {
        weight = 50;
    }
    Dumbell(int w) { weight = w; }
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
    Dumbell d;  // the constructor is taking no arguments and is setting the weight property to 50
    Dumbell d2{25};  // second variable is using the overloaded constructor
    // sidenote : always use brace syntax for initializing objects, they always work the way they're intended all the time
    // initing with parenthesis can be confused sometimes with function declaration

    Dumbell fun();
    // this will be parsed by the compiler as a function that takes no arguments and returns an object of type Dumbell

    Dumbell *d_ptr = new Dumbell(40);  // allocating memory to the pointer of Dumbell type

    printf("Weight of the dumbell is = %d\n", d.getWeight());
    printf("Weight of the dumbell 2  is = %d\n", d2.getWeight());
    printf("Weight of the 3rd dumbell = %d\n", d_ptr->getWeight());
    return 0;
}
