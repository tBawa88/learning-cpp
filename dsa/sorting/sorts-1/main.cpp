#include <time.h>

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "support.cpp"

const int LOW = 10;
const int HIGH = 10000000;

using namespace std;

void selectionSort(vector<int>& v);
void insertionSort(vector<int>& v);
bool isSorted(vector<int>& v);
void swap(int i, int j, vector<int>& v);

int main() {
    for (int N = LOW; N < HIGH; N *= 2) {
        vector<int> v;
        makeRandomVector(LOW, HIGH, N, v);

        auto start = chrono::high_resolution_clock::now();
        selectionSort(v);
        // insertionSort(v);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "Time taken : " << duration.count() << "ms" << endl;
    }

    return 0;
}

void selectionSort(vector<int>& v) {
    int minIndex;
    for (int i = 0; i < v.size(); i++) {
        minIndex = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap(i, minIndex, v);
    }
    if (!isSorted(v)) {
        throw runtime_error{"Array is not sorted"};
    }
}

void insertionSort(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {
        int j = i;
        while (j > 0) {
            if (v[j] < v[j - 1]) {
                swap(j, j - 1, v);
            } else {
                break;
            }
            j--;
        }
    }
    if (!isSorted(v))
        throw runtime_error{"Array is not sorted"};
}

bool isSorted(vector<int>& v) {
    bool sorted = true;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < v[i - 1]) {
            sorted = false;
            break;
        }
    }
    return sorted;
}

void swap(int i, int j, vector<int>& v) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
