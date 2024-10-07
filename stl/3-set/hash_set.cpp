#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
/**
 * unordered set OR hashsets implement a hash table under the hood, so they have a really fast lookup time as compared to normal sets
 * But they store elements in an "un-ordered" fashion, whereas sets store elements in either ascending or descending order
 *
 * So if you want to access the data frequently without worrying about the order, use hash_set<>
 * But if you can sacrifice a bit of runtime in exchange of maintaining a sorted order, use a set<>
 */

void printset(std::unordered_set<int>& s) {
    for (auto el : s) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::unordered_set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(40);

    printset(s);

    s.erase(50);
    printset(s);

    s.erase(99);  // element doesn't exist, so this function does nothing
    printset(s);

    std::unordered_set<int> h;
    h.insert(1);
    h.insert(55);

    // can iterate over it like a normal sequence using an iterator or a for-each loop
    for (auto it = h.begin(); it != h.end(); it++) {
        std::cout << *it << std::endl;
    }

    // compound collections : collections of collections
    std::vector<std::unordered_set<int>> v;
    v.push_back(s);

    printset(v[0]);
    return 0;
}
