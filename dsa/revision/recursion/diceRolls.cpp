#include <iostream>
#include <string>
/**
 * Write a function which takes in number of dice and prints out all the possible combinations of possible dice throws
 * For eg:
 *  diceRolls(0) = ""
 *  diceRolls(1) = 1 2 3 4 5 6
 *  diceRolls(2) = 11 12 13 14 15 16 | 21 22 23 24 25 26 ....
 *  the problem is self similar in this way => "1" + diceRolls(1) , "2" + diceRolls(1), "3" + diceRolls(1) ...
 *  diceRolls(3) = 111 112 113 114 115 116 | 121 122 123 124 125 126 ...
 */

void PrintDiceRolls(int n);
void diceRollheper(int n, std::string prefix = "");
void printRolls(std::string prefix);

void PrintDiceRolls(int n) {
    diceRollheper(n);
}

void diceRollheper(int n, std::string perfix) {
    if (n == 1) {
        printRolls(perfix);
    } else {
        std::string dice = "123456";
        for (char i : dice) {
            diceRollheper(n - 1, perfix + i);
        }
    }
}

void printRolls(std::string prefix) {
    std::string dice = "123456";
    for (char i : dice) {
        std::cout << prefix + i << std::endl;
    }
}
