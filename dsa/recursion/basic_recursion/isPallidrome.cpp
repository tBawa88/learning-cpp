#include <iostream>
#include <string>
/**
 * Create a 'recursive' function called isPallindrome(string) which returns whether the given string is a pallindrome or not
 */

bool isPallindrome(std::string &);
std::string reverseString(std::string);

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

std::string reverseString(std::string s) {
    // base case
    if (s.length() == 1)
        return s;

    // extracting last char of string, constructing a new string using it
    std::string newstr(1, s[s.length() - 1]);

    // recursive call
    return newstr + reverseString(s.substr(0, s.length() - 1));
}

bool isPallindrome(std::string &s) {
    std::string reverse = reverseString(s);
    std::cout << "reverse string: " << reverse << std::endl;
    return s == reverse;
}

// "" + (m a d a m)
// "" + (a d a m)
// "" + (d a m)
// "" + (a m)
// "" + (m) => returns "m"
// returns m
