#include <iostream>
#include <string>
#include <unordered_map>

void printFrequency(const std::unordered_map<char, int>& m) {
    std::cout << "Character\tFrequency" << std::endl;
    for (auto pr : m) {
        std::cout << pr.first << "\t" << pr.second << std::endl;
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

    return 0;
}
