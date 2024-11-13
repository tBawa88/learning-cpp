

#include <iostream>
#include <string>
void greet(std::string& name);

int main() {
    std::string name;
    std::cin >> name;
    greet(name);

    return 0;
}


void greet(std::string& name) {
    std::cout << "Hello there " << name << "How are you doing?" << std::endl;
}
