/**
 * Always try to implement either copy constructor or copy assignment operator for clean hand-off
 * But if the class is simple, then you can use the default copy behavior of the compiler using "default" keyword
 */

struct Rectangle {
    Rectangle(Rectangle &R) = default;
    Rectangle &operator=(Rectangle const &R) = default;
};

// anytime this rectangle class is copied, the compiler will choose the default copy behavior

/**
 * If you have a complex class that contains resources like files, printers, network connections etc. You might want to prevent copying at all
 */
struct Square {
    Square(Square const &S) = delete;
    Square &operator=(Square const &S) = delete;
};
/**
 * Square a{10};
 * Square b{a};     // This will be a compiler error
 */
