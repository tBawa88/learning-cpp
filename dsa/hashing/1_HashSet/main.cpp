#include <iostream>

#include "HashSet.h"

using namespace std;

int main() {
    HashSet<int> s{279};

    for (int i = 0; i < 350; i++) {
        s.insert(i);
    }

    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << "node value " << *it << endl;
    }

    return 0;
}
