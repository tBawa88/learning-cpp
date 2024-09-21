#include <iostream>

// A literal is a fixed value that is not stored inside a variable but is directly stored in the memory
// it's used to assign vales to variables

int main() {
    int age{25};
    // here 25 is a int literal, when this program is compiled, this value will be embedded in the binary code
    // 25 is actually in independed entity, and we're using it to assign a value of 25 to 'age' variable

    10;  // (int)10 , literal can literally live like this in the code and it's completely fine

    "This is a string literal, just chilling inside the code";

    true;  // this is a bool literal

    23423.3245;  // this is a double literal

    std::cout << "age = " << age << std::endl;
    return 0;
}
