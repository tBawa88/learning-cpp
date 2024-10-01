#include <iostream>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
/**
 * This is defining a macro called watch. It takes in a value, prints it's name (#x converts x into string) and prints it's value
 * A Macro is named variable which gets replaced by it's definition during the 'preprocessing step'.
 * It is a way to create re-usable code snippets or constants
 * SO watch() is literally a place holder for the underlying code that prints the value
 */

int main() {
    // A collection of fixed size where type of each elment is fixed
    std::tuple<int, int, int> t1{1, 2, 3};
    std::tuple<int, int> t2{2, 6};

    // accessing values in a tuple
    std::cout << std::get<0>(t1) << "\t" << std::get<1>(t1) << std::endl;

    // make_tuple() makes a temporary tuple
    // std::tie() unpacks that tuple and binds it's values to individual variables
    int a, b, c;
    char d;
    std::tie(a, b, c) = std::make_tuple(69, 420, 101);
    watch(a), watch(b), watch(c);

    std::tie(d, a, c) = std::make_tuple('!', 55, 33);
    watch(d), watch(a), watch(c);

    int x, y;
    std::tie(x, y) = t2;
    watch(x), watch(y);

    /**
     * Comma operator is used to evaluate expressions in a sequence from left to right
     * Each starts from the left, evaluates the expression, discards it and moves to the right
     */

    return 0;
}
