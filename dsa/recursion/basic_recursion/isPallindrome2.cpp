#include <iostream>
#include <string>
/**
 * This solution does not reverses the string.
 * We compare 2 characters at one time, the first and the last
 * Then next time, we strip of these 2 characters and again compare first and last
 * If at any point, first and last are not the same, then return false
 * If we reach a point where string.length() <= 1, return true since a single char is a pallindrome
 *
 */

bool isPallindrome(std::string);

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::cin >> s;

    if (isPallindrome(s)) {
        std::cout << "TRUE\n";
    } else {
        std::cout << "FALSE\n";
    }

    return 0;
}

bool isPallindrome(std::string s) {
    if (s.length() < 2) {
        return true;
    } else {
        char first = s[0];
        char last = s[s.length() - 1];
        if (first == last) {
            return s.length() <= 3 ? true : isPallindrome(s.substr(1, s.length() - 2));
        } else {
            return false;
        }
    }
}
