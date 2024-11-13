#include <ctime>
#include <random>
#include <vector>

using namespace std;
int RandomInt(int low, int high) {
    double d = double(rand()) / (double(RAND_MAX) + 1);
    int k = int(d * (high - low));
    return k + low;
}

void makeRandomVector(int low, int high, int N, vector<int>& v) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        v.push_back(RandomInt(low, high));
    }
}
