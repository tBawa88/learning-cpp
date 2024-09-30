#include <cstdio>
#include <iostream>
#include <set>

// creating a type alias using the existing pair to represent a point in 2D
using Point = std::pair<int, int>;

void displaySet(std::set<std::pair<int, int>>& pairSet) {
    std::set<std::pair<int, int>>::const_iterator it;
    for (it = pairSet.begin(); it != pairSet.end(); it++) {
        printf("{%d , %d}\n", it->first, it->second);
    }
}

int main() {
    std::set<Point> point_set;
    point_set.insert(std::make_pair(10, 20));
    point_set.insert(std::make_pair(23, 1));
    point_set.insert(Point{34, 22});  // using the move constructor (since we're passing a rvalue)
    point_set.insert(Point{2, 5});

    displaySet(point_set);
    /**
     * {10,20} is evaluated to be less than {23,1} because 23 > 10 even tho 1 < 20
     */

    return 0;
}
