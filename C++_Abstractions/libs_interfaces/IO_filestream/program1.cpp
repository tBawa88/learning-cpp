/**
 * File : program1.cpp
 * -------------------
 * The purpose of this file is to be fed into the CopyWithoutComments() function
 * which reads the text data of this file and copies it to another file called program2.cpp
 * removing all the comments.
 */

#include <iostream>
#include <string>
void greet(std::string& name);

int main() {
    std::string name;
    std::cin >> name;
    greet(name);

    return 0;
}

/*greet(): takes in a name string and prints out a greeting addressed to that name*/
void greet(std::string& name) {
    std::cout << "Hello there " << name << "How are you doing?" << std::endl;
}
