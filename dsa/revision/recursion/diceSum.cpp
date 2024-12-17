#include <iostream>
#include <string>
#include <vector>

/**
 * Write a function called diceSum(int dice, int sum), similar to diceRoll(int dice) which accpets another parameter called "SUM"
 * IT only prints those combinations which when added gives this integer sum
 *
 * For example : diceSum(2,7) = (1,6) (2,5) (3,4) (4,3) (5,2) (6,1)
 *
 * SOLUTION:
 * - need a vector of int to represent current dice throw state
 **/

void DiceSum(int numDice, int targetSum);
void diceSumHelper(int numDice, int targetSum, std::vector<int> combination, int& iterations);
int getSum(std::vector<int>& combination);
void printDiceThrow(std::vector<int>& combination);

void DiceSum(int numDice, int targetSum) {
    int iterations = 0;
    std::vector<int> combination = {};
    diceSumHelper(numDice, targetSum, combination, iterations);
    std::cout << "total iterations = " << iterations << std::endl;
}

// Helper function to try out all the possible dice throws
void diceSumHelper(int numDice, int targetSum, std::vector<int> combination, int& iterations) {
    ++iterations;
    if (numDice == 0) {
        if (getSum(combination) == targetSum)
            printDiceThrow(combination);
        return;
    }

    for (int face = 1; face <= 6; face++) {
        //                   the sum so far +  currentDice face +  adding 1s from the remaining dice throws
        int minPossibleSum = getSum(combination) + face + (numDice - 1) * 1;
        //                   the sum so far +  currentDice face +  adding 6s from the remaining dice throws
        int maxPossibleSum = getSum(combination) + face + (numDice - 1) * 6;
        // if this condition is true, this mean the current branch is a waste of compute
        // therefore, no need to choose the current dice face and explore down this path
        if (minPossibleSum > targetSum || maxPossibleSum < targetSum)
            continue;

        combination.push_back(face);
        diceSumHelper(numDice - 1, targetSum, combination, iterations);
        combination.pop_back();
    }
}

// Function to print the dice throws that match the target sum
void printDiceThrow(std::vector<int>& combination) {
    std::cout << "{";
    for (int i = 0; i < combination.size(); i++) {
        std::cout << combination[i];
        if (i != combination.size() - 1)
            std::cout << ",";
    }
    std::cout << "}\n";
}

// Function to obtain the total sum of current dice throw
int getSum(std::vector<int>& combination) {
    int sum = 0;
    for (int i : combination)
        sum += i;
    return sum;
}
int getMaxPossibleSum(std::vector<int>& combination, int face) {
    int sum = 0;
    for (int i : combination)
        sum += i;
    return sum;
}
