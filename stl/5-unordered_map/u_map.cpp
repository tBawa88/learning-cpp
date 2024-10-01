#include <iostream>
#include <string>
#include <unordered_map>

void printFrequency(const std::unordered_map<char, int>& m) {
    std::cout << "Character\tFrequency" << std::endl;
    for (auto pr : m) {
        std::cout << pr.first << "\t\t" << pr.second << std::endl;
    }
}

int main() {
    std::unordered_map<char, int> um;

    std::string name;
    std::cout << "Enter your name" << std::endl;
    std::cin >> name;
    for (auto c : name) {
        um[c] += 1;
    }

    printFrequency(um);
    std::cout << "accessing invalid key " << um['~'] << std::endl;

    printFrequency(um);
    // same as normal maps, accessing an invalid key adds it to the map
    try {
        um.at('!');  // throws an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    um.at('x');
    return 0;
}
