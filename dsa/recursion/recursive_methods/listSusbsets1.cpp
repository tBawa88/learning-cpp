#include <iostream>
#include <set>
#include <vector>

/**
 * This approach is obviously inefficient since we're using an auxiliary data structure
 */

void ListSubsets(std::vector<char>& list);
void SubsetHelper(std::vector<char> list, std::set<std::vector<char>>& Set);
void printListSet(std::set<std::vector<char>>& Set);

int main() {
    std::vector<char> list{'A', 'B'};
    ListSubsets(list);
    return 0;
}

void ListSubsets(std::vector<char>& list) {
    std::set<std::vector<char>> Set;
    SubsetHelper(list, Set);
    Set.insert(std::vector<char>{});
    printListSet(Set);
}

void SubsetHelper(std::vector<char> list, std::set<std::vector<char>>& Set) {
    if (!list.empty()) {
        Set.insert(list);
        for (int i = 0; i < list.size(); i++) {
            auto newlist = list;
            newlist.erase(newlist.begin() + i);
            if (!Set.contains(newlist)) {
                SubsetHelper(newlist, Set);
            }
        }
    }
}

void printListSet(std::set<std::vector<char>>& Set) {
    for (auto l : Set) {
        std::cout << "[";
        for (int i = 0; i < l.size(); i++) {
            std::cout << l[i];
            if (i < l.size() - 1)
                std::cout << ",";
        }
        std::cout << "]\n";
    }
}
