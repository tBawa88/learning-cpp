#include <iostream>
#include <vector>
/**
 *
 * SOLUTION: classic backtracking solution to exhaust all possible combinations of dice throws
 *  Add a dice face value to the vector - choose
 *  Explore the Path with that value - explore
 *  Remove that value from the vector - unchoose
 */

void DiceRolls(int dice);
void diceRollsHelper(int dice, std::vector<int>& combination);
void printDiceCombination(std::vector<int>& combination);

void DiceRolls(int dice) {
    std::vector<int> chosen = {};
    diceRollsHelper(dice, chosen);
}

void diceRollsHelper(int dice, std::vector<int>& combination) {
    if (dice == 0) {
        printDiceCombination(combination);
        return;
    }

    for (int i = 1; i <= 6; i++) {
        combination.push_back(i);
        diceRollsHelper(dice - 1, combination);
        combination.pop_back();
    }
}

void printDiceCombination(std::vector<int>& combination) {
    std::cout << "{";
    for (int i = 0; i < combination.size(); i++) {
        std::cout << combination[i];
        if (i != combination.size() - 1)
            std::cout << ",";
    }
    std::cout << "}" << std::endl;
}
