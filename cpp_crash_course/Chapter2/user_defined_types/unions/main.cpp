#include <cstdio>

/**
 * They're somewhat similar to POD's (structs) but there is a big difference
 *  A Union type stores all of it's data members in a single memory block
 *  Whereas in a struct, each memeber get's it's own memory
 * Due to this reason, you can only store one value at a time in a Union type
 *
 * Think of a union type in typescript
 * let value = string | number | boolean; The value can store either one of these types, but only one can be stored at one time
 */

union Data {
    int i;
    char c;
    double f;
    bool b;
};

int main() {
    Data d;

    d.i = 100;
    printf("d.i = %d\n", d.i);

    d.b = true;
    printf("d.b = %d\n", d.b);

    // Notice that we have not specified the value of d.c,
    // BUT since union types share memory between their members, all members will hold the same value at any given time
    printf("d.c = %d\n", d.c);
    return 0;
}
