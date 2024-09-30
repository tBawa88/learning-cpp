#include <algorithm>
#include <iostream>
#include <set>

void displaySet(std::set<int>& s) {
    for (auto i : s) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::set<int> s;
    s.insert(-10);
    s.insert(3);
    s.insert(-29);
    s.insert(33);
    s.insert(10);
    displaySet(s);

    // s.erase(-10);  // erases the given key if it's found in the set
    displaySet(s);

    auto num = s.find(3);  // returns an iterator pointing to the element or returns end() if element not found
    if (num != s.end())
        std::cout << "Found element = " << *num << std::endl;

    auto upper = s.upper_bound(10);  // iterator pointing to first element greater than the key, or end()
    auto lower = s.lower_bound(100);  // iterator pointing to the first element that is *not less than the key* or end

    if (upper != s.end())
        std::cout << "Upper bound = " << *upper << std::endl;

    if (lower != s.end())
        std::cout << "Lower bound  " << *lower << std::endl;
    else
        std::cout << "Lower bound does not exist" << std::endl;

    return 0;
}
