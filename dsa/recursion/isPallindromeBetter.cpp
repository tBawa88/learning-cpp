#include <iostream>
#include <string>

bool isPallindrome(std::string&);
bool pallindromeHelper(std::string&, int, int);

int main() {
    std::string s;
    std::cin >> s;

    if (isPallindrome(s))
        std::cout << "PALLINDROME" << std::endl;
    else
        std::cout << "NOT PALLINDROME" << std::endl;

    return 0;
}

bool isPallindrome(std::string& s) {
    return pallindromeHelper(s, 0, s.size() - 1);
}

bool pallindromeHelper(std::string& S, int first, int last) {
    if (first >= last) return true;  // First == Last ;means string is 1 character | First > Last means the string is empty

    return (S[first] == S[last] && pallindromeHelper(S, first + 1, last - 1));
}
