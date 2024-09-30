#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using studentmap = std::map<std::string, int>;

void printMap(std::map<std::string, int>& m) {
    std::cout << "Student\tRollNo" << std::endl;
    for (auto it : m) {
        std::cout << it.first << "\t" << it.second << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    studentmap s;
    s["alice"] = 1909;  // overloaded move subscript operator
    s["bob"] = 1335;
    s["jason"] = 4563;

    s.insert(std::make_pair("kelly", 1800));  // since every element inside a map is a pair
    printMap(s);

    // accessing key that does not exist
    std::cout << "Size of map before accessing invalid key = " << s.size() << std::endl;
    auto it = s["lmfao"];
    std::cout << it << std::endl;  // it prints a zero value according to the type of value
    std::cout << "Size of map after accessing invalid key = " << s.size() << std::endl;

    // this proves that if we try to access a key that doesn't exist inside the map, it adds that key and maps it to a zero value of the mapped type

    /**
     * To make sure an invalid key is not inserted into the map, use the at() method
     * But this method throws an exception if key is not found
     */
    try {
        std::cout << s.at("invalid key");
    } catch (std::exception& e) {
        std::cout << "Key not found " << e.what() << std::endl;
    }

    return 0;
}
