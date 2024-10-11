#include <iostream>
#include <set>
#include <vector>

/**
 * Write a function printSublist(vector<int>) which takes a list and outputs """all possible sublists""" of that list, ensuring the order of the elements remain same.
 * A list is sublist if it contains n <= list.length <= 0 total elements
 *
 * BTW = we could also call this function printPowerSet() because a PowerSet is a set of all subsets of a given set. (just random fact from set theory)
 *
 */
void sublist(std::vector<int>& list);
void sublistHelper(std::vector<int> list, std::set<std::vector<int>>& sublistList);
void printset(std::set<std::vector<int>>& sublistList);
void printvector(std::vector<int>& v);
int main() {
    std::vector<int> v = {1, 2, 3};
    sublist(v);
}

void sublist(std::vector<int>& list) {
    std::set<std::vector<int>> sublistList{std::vector<int>{}};
    sublistHelper(list, sublistList);
    printset(sublistList);
}

void sublistHelper(std::vector<int> list, std::set<std::vector<int>>& sublistList) {
    if (list.size() == 0) {
        return;
    }

    sublistList.insert(list);  // each list we choose qualifies as a sublist of the original list, insert it in the set
    for (int i = 0; i < list.size(); i++) {
        // Remove current element, CHOOSE the rest of the List
        std::vector<int> newlist = list;
        newlist.erase(newlist.begin() + i);

        // this is to optimize. if the newlist already exists inside the set that means we've already explored that path before (and we only need to print once)
        // becuase there will be a lot of redundant calls (the single element lists will always be explored if we don't check)
        if (!sublistList.contains(newlist))
            sublistHelper(newlist, sublistList);  // EXPLORING

        // This time we don't need to explicitly UNCHOOSE, the loop and how we're chopping the list by one element
    }
}

void printset(std::set<std::vector<int>>& sublistlist) {
    for (auto list : sublistlist)
        printvector(list);
}
void printvector(std::vector<int>& v) {
    std::cout << "[";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i != v.size() - 1)
            std::cout << ",";
    }
    std::cout << "]" << std::endl;
}
