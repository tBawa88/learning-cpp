#include "random.h"

#include <cstdlib>
#include <ctime>

int RandomInt(int low, int high) {
    // generates a double between 0.0 (incl) and 1.0 (excl). max value rand() can produce is RAND_MAX and
    // since we're dividing by RAND_MAX + 1, the
    double d = double(rand()) / (double(RAND_MAX) + 1);
    // then scale that fraction and bring it inside our range
    int k = int(d * (high - low));
    // add low to make it low inclusive (now the min value is low <= value < high)
    return k + low;
}

double RandomReal(double low, double high) {
    double d = double(rand()) / (double(RAND_MAX) + 1);
    double k = d = (high - low);
    return k + low;
}

bool RandomProb(double p) {
    return RandomReal(0.0, 1.0) < p;
}

void Randomize() {
    // seed the random value with current time to make it truly random
    srand(int(time(NULL)));
}
