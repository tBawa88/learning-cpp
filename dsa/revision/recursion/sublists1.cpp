#include <iostream>
#include <string>
#include <vector>
/**
 * Given a set(list) of characters, print all the possible subsets of the set  (here set means the mathematical conceptual set)
 * -------------------------------------------------------------------------
 * This is the classic choose - explore - unchoose , recursive backtracking problem
 *
 */

void ListSubsets(std::vector<char>& list);
void subsetHelper(std::vector<char> available, std::vector<char> chosen = {});
void printSubset(std::vector<char>& choice);

void ListSubsets(std::vector<char>& list) {
    subsetHelper(list);
}

void subsetHelper(std::vector<char> available, std::vector<char> chosen) {
    if (available.empty()) {
        printSubset(chosen);
    } else {
        // Extract the front most element from the available set
        char front = available[0];
        available.erase(available.begin());

        // CHOOSE : push this element to the chosen set
        chosen.push_back(front);

        // EXPLORE : explore more subsets with the current state of chosen and available
        // think of this as the left subtree
        subsetHelper(available, chosen);

        // UNCHOOSE: pop this choice from the chosen set
        chosen.pop_back();

        // EXPLORE : again explore this path
        // think of this as the right subtree
        subsetHelper(available, chosen);
    }
}

void printSubset(std::vector<char>& choice) {
    std::cout << "{";
    for (int i = 0; i < choice.size(); i++) {
        std::cout << choice[i];
        if (i != choice.size() - 1)
            std::cout << ",";
    }
    std::cout << "}\n";
}
