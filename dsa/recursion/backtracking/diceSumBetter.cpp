#include <iostream>
#include <vector>

/**
 * This approach aims to eliminate all those paths that will guaranteed lead to ""incorrect"" output.
 * This is a method of optimizing the recursive backtracking which is performing an ehaustive search which is a brute force algorithm
 */

void diceSum(int dice, int targetSum);
void diceRollHelper(int dice, int sum, int sumSofar, std::vector<int>& chosen, std::vector<std::vector<int>>& result);
bool isSumEqual(int sum, std::vector<int>& comb);
void printCombination(std::vector<int>&);

int totalCalls = 0;
int main() {
    diceSum(4, 9);
    std::cout << "total calls of recursion: " << totalCalls << std::endl;
}

void diceSum(int dice, int targetSum) {
    std::vector<int> chosen;
    std::vector<std::vector<int>> result;
    diceRollHelper(dice, targetSum, 0, chosen, result);

    for (auto combination : result) {
        printCombination(combination);
    }
}

void diceRollHelper(int dice, int targetSum, int sumSofar, std::vector<int>& chosen, std::vector<std::vector<int>>& result) {
    totalCalls++;

    if (dice == 0) {
        // now we don't need to sum up all the elements of the chosen vector
        // if (sumSofar == targetSum)
        //     result.push_back(chosen);

        /**
         * INFACT: we don't even need an if statement with this approach.
         * Because we're only making calls whose potential sum is not too big and not too small, we will always end up at the correct final outcome
         * hence we can directly add that combination to our result vector
         */
        result.push_back(chosen);
        return;
    }

    for (int faceVal = 1; faceVal <= 6; faceVal++) {
        /**
         * PRUNE: before making a choice and exploring a path, we check if that path is bad or not
         * Checking 2 conditions
         * 1. if the min possible sum is already greater than targetSum
         * 2. if the max possible sum will always be less than targetSum
         */
        // sumSofar + current faceValue of die that we're about to try + plus remaining dice minus this one
        int minPossibleSum = sumSofar + faceVal + (dice - 1) * 1;
        int maxPossibleSum = sumSofar + faceVal + (dice - 1) * 6;
        if ((minPossibleSum > targetSum) || (maxPossibleSum < targetSum))
            continue;  // SKIP the current path
        chosen.push_back(faceVal);  // MAKE CHOICE
        diceRollHelper(dice - 1, targetSum, sumSofar + faceVal, chosen, result);  // EXPLORE PATH RECUSIVELY
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
