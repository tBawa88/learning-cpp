
#include <cstdio>

/**
 *  Enumeration or Enums are user defined dts, that consist of intergral constants under that hood
 * It let's us give alphanumeric string names to the underlying integers to make the code more readable
 *
 * It can be declared using either the 'enum <enum_name>' or 'enum class <enum_name>'
 * First one is unscoped enum, the second is called scoped enum
 *
 */

// unscoped enums
enum Direction {
    North,  // by default starts with 0
    East,  // 1
    South,  // 2
    West  // 3
};

enum class Day {
    Sunday = 1,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {
    Direction dir1 = North;
    Direction dir2 = South;

    Day d1 = Day::Saturday;
    Day d2 = Day::Monday;

    // compare them either with their integral values or with d1 == Day::Monday
    //
}
