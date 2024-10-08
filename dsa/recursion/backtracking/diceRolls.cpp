#include <iostream>
#include <string>

/**
 * Write a recursive function which accepts the number of 6-faced dice and prints out all the combinations possible of dice throws
 *
 * SOLUTION:
 * Every face of each dice could match with every face of other die
 * dice(0) = ""
 * dice(1) = 1 2 3 4 5 6
 * dice(2) = 11 12 13 14 15 16 | 21 22 23 24 25 26 | ... | 61 62 63 64 65 66
 * dice(3) = 111 112 113 114 115 116 | 121 122 123 124 125 126 | .. | 661 662 663 664 665 666
 *
 * There is a same recurring pattern which relates dice(n) with dice(n-1) and there is also a base case
 */

void diceRolls(int dice, std::string prefix = "");

int main() {
    diceRolls(3);
}

void diceRolls(int dice, std::string prefix) {
    if (dice == 0) {
        std::cout << prefix << std::endl;
        return;
    }

    for (int i = 1; i <= 6; i++)
        diceRolls(dice - 1, prefix + std::to_string(i));
}
