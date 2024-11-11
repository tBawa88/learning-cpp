#include <iostream>

#include "HashSet.h"

using namespace std;

int main() {
    HashSet<int> s{279};

    for (int i = 0; i <= 230; i++) {
        s.insert(i);
    }

    s.remove(8989898);
    cout << "Sizeo of set = " << s.size() << endl;
    return 0;
}
