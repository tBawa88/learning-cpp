#include <iostream>
#include <string>
#include <vector>

/**
 * QUESTION:
 * Write a function called void stringPermute(string), which takes in a string parameter
 * and outputs all possible arragements of the characters present in the string
 *
 * APPROACH:
 * - "All possible arrangements" -> this is recursive backtracking type beat if i ever seen one
 *
 *
 */
void stringPermute(std::string str);
void permute(std::string choice, std::string& chosen);

int main() {
    stringPermute("ABC");
}

void stringPermute(std::string str) {
    std::string chosen = "";
    permute(str, chosen);
}

void indent(int n) {
    for (int i = 0; i < n; i++)
        std::cout << "    ";
}

void permute(std::string choice, std::string& chosen) {
    indent(chosen.length());
    std::cout << "permute(" << choice << ", " << chosen << ")" << std::endl;
    if (choice.length() == 0) {
        std::cout << chosen << std::endl;
        return;
    }

    // walking over the entire string and choosing each character one by one, then exploring the entire path with that character as the first choice
    for (int i = 0; i < choice.length(); i++) {
        // CHOOSING
        chosen.push_back(choice[i]);

        std::string remainingChoice = choice;  // creating a copy of the string and removing current choice from it
        remainingChoice.erase(i, 1);
        // EXPLORING
        permute(remainingChoice, chosen);
        // UN-CHOOSING
        chosen.pop_back();
    }
}
