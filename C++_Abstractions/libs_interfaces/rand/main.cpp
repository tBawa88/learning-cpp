#include <iomanip>
#include <iostream>

#include "random.h"

const int LOW = 100;
const int HIGH = 100000;

using namespace std;
int main() {
    Randomize();
    for (int i = 0; i < 1000; i++) {
        cout << setw(5) << RandomInt(LOW, HIGH) << endl;
    }

    return 0;
}
