#include <iostream>
#include <vector>

using namespace std;
/**
 * This approach follows the backtracking philosophy and uses a vector to store all the choices we've made untill we hit the leaf node of the decision tree
 * The general steps in a backtracking algorithm are:
 *  Explore (decisions):
 *      if no more decisions left
 *          return;
 *      else: for available choice C, for this decision
 *          Choose C
 *          Explore remaining choices recursivley
 *          Un-Choose C
 *
 */

// Since the diceRoll() function doesn't take a vector, we can use a helper functoin to help with our recusive function

void diceRoll(int);
void diceRollHelper(int, vector<int>&);
void printchoice(vector<int>&);
int main() {
    diceRoll(4);
    return 0;
}

void diceRoll(int dice) {
    vector<int> chosen;
    diceRollHelper(dice, chosen);
}

void diceRollHelper(int dice, vector<int>& chosen) {
    if (dice == 0) {  // NO MORE CHOICES TO MAKE
        printchoice(chosen);
        return;
    }

    // for every die we want to make 6 different choices
    for (int i = 1; i <= 6; i++) {
        chosen.push_back(i);  // MAKE CHOICE for this decision
        diceRollHelper(dice - 1, chosen);  // letting recursion make the rest of the chocies
        chosen.pop_back();  // UNDO CHOICE and make room for next choices
    }
}

/**
 * Think about it for a second
 * Assume you're chosing 1 for each dice value
 *  Push 1 into the array
 * You explore all the way to the leaf node for the 1 value
 * Then we have to come back, and choose another value for the most recent dice we just explored
 * Therfore we have to pop the array and choose another value
 *
 *
 * This also explains why we were popping the array while printing the binary after exploring all paths with current choice
 */

void printchoice(vector<int>& chosen) {
    cout << "{";
    for (int i : chosen)
        cout << i << ",";
    cout << "}" << endl;
}
