#include <iostream>

#include "ArrayList.h"

int main() {
    ArrayList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);

    std::cout << list << std::endl;
    list.remove(0);
    std::cout << list << std::endl;
    list.remove(1);
    std::cout << list << std::endl;
    list.pop();
    std::cout << list << std::endl;

    return 0;
}
