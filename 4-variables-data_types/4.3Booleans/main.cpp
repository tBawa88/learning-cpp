#include <iostream>

int main () {
    bool red_light{false};
    bool green_light{true};

    if (red_light){
        std::cout << "Stop, it's the red light" << std::endl;
    }

    if (green_light){
        std::cout << "Floor it mayne" << std::endl;
    }

    std::cout << red_light << std::endl;    // if we directly print a boolean like this, it will be converted into either 1 or 0

    // to print true or false, set the boolapha to the output stream
    std::cout << std::boolalpha;
    std::cout << green_light << std::endl;

    return 0;
}
