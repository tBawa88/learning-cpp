#include <iostream>
#include <set>
#include <vector>

/**
 * The previous solutions is "INEFFICIENT"
 * BETTER:
 *  Instead of looping over the entire list each time, leaving out one element and choosing the rest
 *  We can make 2 decisions per function call.
 *  - Include the first element of list
 *  - Not include the first elment of list
 * And explore 2 different paths for each of these 2 cases
 */

void sublist(std::vector<int>& list);
void sublistHelper(std::vector<int> list, std::vector<int>& chosen);
void printlist(std::vector<int>&);

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    sublist(v);
}
void sublist(std::vector<int>& list) {
    std::vector<int> chosen;
    sublistHelper(list, chosen);
}

/**
 * At all times, chosen vector will contain the sublist for each decision path
 */
void sublistHelper(std::vector<int> list, std::vector<int>& chosen) {
    if (list.size() == 0) {
        printlist(chosen);
        return;
    }

    int first = list[0];
    list.erase(list.begin());

    chosen.push_back(first);  // CHOOSE: include first
    sublistHelper(list, chosen);  // EXPLORE: path with first present inside chosen

    chosen.pop_back();  // CHOOSE: not include first
    sublistHelper(list, chosen);  // EXPLORE: path without first present inside chosen

    // we only need to pop chosen after the first call, because every function call will remember value of list
    // if we decided to pass the reference of the list to each function, then we would have to re-insert the first value in list here
}

void printlist(std::vector<int>& v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}
