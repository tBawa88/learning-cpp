#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void ListMnemonics(std::string& num);
void mnemonicsHelper(std::string num, std::unordered_map<char, std::string>& keymap, std::string prefix = "");
void printCombination(std::string& prefix, std::string& charString);
int main() {
    std::string s;
    std::cin >> s;
    ListMnemonics(s);
    return 0;
}

void ListMnemonics(std::string& num) {
    std::unordered_map<char, std::string> keymap;
    keymap.insert(std::make_pair('2', "ABC"));
    keymap.insert(std::make_pair('3', "DEF"));
    keymap.insert(std::make_pair('4', "GHI"));
    keymap.insert(std::make_pair('5', "JKL"));
    keymap.insert(std::make_pair('6', "MNO"));
    keymap.insert(std::make_pair('7', "PQRS"));
    keymap.insert(std::make_pair('8', "TUV"));
    keymap.insert(std::make_pair('9', "XYZW"));
    mnemonicsHelper(num, keymap);
}

void mnemonicsHelper(std::string num, std::unordered_map<char, std::string>& keymap, std::string prefix) {
    if (num.length() == 1) {
        auto charString = keymap[num[0]];
        printCombination(prefix, charString);
    } else {
        auto charString = keymap[num[0]];
        auto newstr = num.substr(1);
        for (char p : charString) {
            mnemonicsHelper(newstr, keymap, prefix + p);
        }
    }
}

void printCombination(std::string& prefix, std::string& charString) {
    for (char c : charString) {
        std::cout << prefix + c << std::endl;
    }
}
