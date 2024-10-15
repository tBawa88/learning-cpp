#include <iostream>
#include <vector>

void ListSubsets(std::vector<char>&);
void subsetHelper(std::vector<char> list, std::vector<char>& chosen);
void printlist(std::vector<char>& list);

int main() {
    std::vector<char> list = {'A', 'B', 'C', 'D'};
    ListSubsets(list);
    return 0;
}

void ListSubsets(std::vector<char>& list) {
    std::vector<char> chosen{};
    subsetHelper(list, chosen);
}

void subsetHelper(std::vector<char> list, std::vector<char>& chosen) {
    if (list.empty()) {
        printlist(chosen);
    } else {
        char firstLetter = list[0];
        list.erase(list.begin());  // remove the first letter from the list

        // CHOOSE FIRST LETTER
        chosen.push_back(firstLetter);
        // EXPLORE THE PATH (left subtree with first element included)
        subsetHelper(list, chosen);

        // UNCHOOSE
        chosen.pop_back();
        // EXPLORE THE PATH (right subtree without the first letter)
        subsetHelper(list, chosen);
    }
}

void printlist(std::vector<char>& list) {
    std::cout << "[";
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i];
        if (i < list.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}
