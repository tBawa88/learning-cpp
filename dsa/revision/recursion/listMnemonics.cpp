#include <iostream>
#include <map>
#include <string>

void generateMnemonics(std::string digitStr, std::map<char, std::string>& letters, std::string chosen = "");
void printMnemonic(std::string chosen, std::string letters);

void ListMnemonics(std::string digitStr) {
    std::map<char, std::string> letters;
    letters['2'] = "ABC";
    letters['3'] = "DEF";
    letters['4'] = "GHI";
    letters['5'] = "JKL";
    letters['6'] = "MNO";
    letters['7'] = "PQRS";
    letters['8'] = "TUV";
    letters['9'] = "WXYZ";

    generateMnemonics(digitStr, letters);
}

void generateMnemonics(std::string digitStr, std::map<char, std::string>& letters, std::string chosen) {
    if (digitStr.length() == 1) {
        printMnemonic(chosen, letters[digitStr[0]]);
    } else {
        for (int i = 0; i < digitStr.length(); i++) {
            std::string newdigitStrtring = digitStr.substr(1);  // slice the string and remove the first character
            std::string letterString = letters[digitStr[0]];  // obtain the letter string associated with the first digit

            // iterate over the obtained letter string from map
            // append each character to the chosen mnemonic string
            for (char let : letterString) {
                generateMnemonics(newdigitStrtring, letters, chosen + let);
            }
        }
    }
}

void printMnemonic(std::string chosen, std::string letters) {
    for (char c : letters)
        std::cout << chosen + c << std::endl;
}
