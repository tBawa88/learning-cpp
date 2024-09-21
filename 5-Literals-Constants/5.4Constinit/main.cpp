#include <iostream>

/**
 * This is C++20 addition
 * It ensures that a variable is initalized at compile time , just like constexpr
 * BUT, unlike constexpr, it doesn't need another constexpr to assign a value to it
 */

constexpr int getValue() { return 10; }

constinit int globeal = getValue();  // initilized at compile time since we're using a constexpr function and not a normal function

int main() {
    constinit static int x = 55;
    // There are 2 big rules associated with constinit
    // consinit cannot be applied to variables that are local to a function like 'x' in this case.
    // (local variables are allocated on the stack and are only valid untill the function remains on the stack)

    // the variable either needs to be static (static variable are allocated memory automatically when the program starts executing and deallocated when the program ends)
    // or the variable needs to be local to a Thread (thread local variables persist as long as the thread lives)
    return 0;
}

/**
 * constinit is completely different from both const and constexpr
 *
 * 1. First of all it doesn't mean that it is a constant value and canot be mutated.
 *      All it means is that this value is guarunteed to be initialized at compile time
 *
 * 2. constinit variables must be initlized by either const or literal values.
 */
