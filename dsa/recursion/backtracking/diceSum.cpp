#include <iostream>
#include <vector>

/**
 * A small variation on the diceRoll(int) function we wrote previously
 *
 * Write a function called diceSum(int dice, int sum), similar to diceRoll(int dice) which accpets another parameter called "SUM"
 * IT only prints those combinations which when added gives this integer sum
 *
 * For example : diceSum(2,7) = (1,6) (2,5) (3,4) (4,3) (5,2) (6,1)
 *
 * SOLUTION:
 * We do the same thing as we did in normal diceRoll(), where we explore all possible branches of a given choice
 * In the base case, we check if the current vector which contains all of our choices for the current path meets the sum requirement or not
 * If it does, we push this vector into another vector called ""result""
 *
 * PROBLEM: WITH: CURRENT: SOLUTION:
 *  This is not the most EFFICIENT solution to this problem.
 * We don't need to explore every possible path to find the desired sum since there are paths that we know will never lead to the desired outcome
 * For example: if dice = 3, and desired sum = 5
 * We know we will never find the sum if we go down the path where die value of the first die is 6, or 5 or 4
 * since the minimum value we can get in those cases is 6(6 + 1 + 1 = 8), 5(5 + 1 + 1), 4(4 + 1 + 1) which are all greater than 5
 *
 * Same way if desired sum is 15, we will never find the sum by walking down the path where the first value of die = 1 (1 + 6 + 6 = 13)
 *
 * CORRECTION:
 * 1. We need to eliminat the paths that we know will result in incorrect output
 * 2. We don't need to check for the sum of each full combination since we're eliminating the incorrect combinations altogether
 *
 */

void diceSum(int dice, int sum);
void diceRollHelper(int dice, int sum, std::vector<int>& chosen, std::vector<std::vector<int>>& result);
bool isSumEqual(int sum, std::vector<int>& comb);
void printCombination(std::vector<int>&);

int main() {
    diceSum(3, 7);
}

void diceSum(int dice, int sum) {
    std::vector<int> chosen;
    std::vector<std::vector<int>> result;
    diceRollHelper(dice, sum, chosen, result);

    for (auto combination : result) {
        printCombination(combination);
    }
}

/**
 * chosen : represents the combincation choice at any instance
 * result : holds all the choices of dice size which compute to the given sum
 */
void diceRollHelper(int dice, int sum, std::vector<int>& chosen, std::vector<std::vector<int>>& result) {
    if (dice == 0) {
        /**
         * INEFFICIENT: the way we're calling isSumEqual() for each base case is INEFFICIENT
         */
        if (isSumEqual(sum, chosen))
            result.push_back(chosen);
        return;
    }

    for (int faceVal = 1; faceVal <= 6; faceVal++) {
        chosen.push_back(faceVal);  // MAKE CHOICE
        diceRollHelper(dice - 1, sum, chosen, result);  // EXPLORE PATH RECUSIVELY
        chosen.pop_back();  // UNDO CHOICE
    }
}

bool isSumEqual(int sum, std::vector<int>& comb) {
    int s = 0;
    for (int i : comb)
        s += i;
    return s == sum;
}

void printCombination(std::vector<int>& comb) {
    std::cout << "{";
    for (int i = 0; i < comb.size(); i++) {
        std::cout << comb[i];
        if (i != comb.size() - 1)
            std::cout << ",";
    }
    std::cout << "}" << std::endl;
}
