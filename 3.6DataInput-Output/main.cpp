#include <iostream>

void greet(std::string name) {
    std::cout << "Hello '" << name << "' how are you doing" << std::endl;
    std::clog << "Greet done \n";
}

int main () {

    std::string name ;
    std :: cout << "Enter your name \n";
    // std::cin >> name;            // std::cin doesn't allow spaces to be inserted in a string
    std::getline(std::cin , name);

    greet(name);
    return 0;
}

