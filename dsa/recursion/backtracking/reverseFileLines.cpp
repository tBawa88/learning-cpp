#include <fstream>
#include <iostream>
#include <string>

/**
 * Write a recursive function which reverses all the lines in a text file.
 */
void reverseFileLines(std::ifstream&);

int main() {
    // this is how you open a file for both reading and writing
    std::ifstream file("file.txt", std::ios::in | std::ios::out);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening the file\n";
        return 1;
    }

    reverseFileLines(file);

    file.close();
    return 0;
}

void reverseFileLines(std::ifstream& input) {
    std::string line;
    if (getline(input, line)) {
        reverseFileLines(input);
        std::cout << line << std::endl;
    }
}
