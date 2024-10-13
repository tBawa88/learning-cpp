#include <iostream>
#include <string>

void ListPermutations(std::string);
void PermutationHelper(std::string, std::string prefix = "");

int main() {
    std::string s;
    std::cin >> s;
    ListPermutations(s);

    return 0;
}

void ListPermutations(std::string str) {
    PermutationHelper(str);
}

void PermutationHelper(std::string str, std::string prefix) {
    if (str.length() == 0) {
        std::cout << prefix << std::endl;
    } else {
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            std::string newstr = str.substr(0, i) + str.substr(i + 1);
            PermutationHelper(newstr, prefix + c);
        }
    }
}
