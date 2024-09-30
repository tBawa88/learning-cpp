#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

void displayVector(const std::vector<char>& v) {
    std::vector<char>::const_iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    int c;
    std::vector<char> chars;
    while ((c = getchar()) != EOF) {
        chars.push_back(c);
    }

    displayVector(chars);

    // sorting the vector in ascending order
    // provide a starting point and an ending point
    std::sort(chars.begin() + 1, chars.end());
    displayVector(chars);
    return 0;
}
