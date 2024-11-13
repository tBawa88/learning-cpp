#include <time.h>

#include <chrono>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "support.cpp"

const int LOW = 10;
const int HIGH = 10000000;

using namespace std;
void mergeSort(vector<int> v);
vector<int> mSort(vector<int> v);
vector<int> mergeTogether(vector<int> listA, vector<int> listB);
bool isSorted(vector<int>& v);
void swap(int i, int j, vector<int>& v);

int main() {
    for (int N = LOW; N < HIGH; N *= 2) {
        vector<int> v;
        makeRandomVector(LOW, HIGH, N, v);

        auto start = chrono::high_resolution_clock::now();
        mergeSort(v);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "Time taken : " << duration.count() << "ms" << endl;
    }

    vector<int> v;
    makeRandomVector(LOW, HIGH, 100, v);
    mergeSort(v);
    return 0;
}

void mergeSort(vector<int> v) {
    vector<int> sortedlist = mSort(v);

    if (!isSorted(sortedlist))
        throw runtime_error{"Array is not sorted"};
}

vector<int> mSort(vector<int> v) {
    if (v.size() < 2)
        return v;

    vector<int> listA(v.begin(), v.begin() + (v.size() / 2));
    vector<int> listB(v.begin() + (v.size() / 2), v.begin() + (v.size() - 1));

    return mergeTogether(mSort(listA), mSort(listB));
}

vector<int> mergeTogether(vector<int> listA, vector<int> listB) {
    vector<int> sortedList;
    int i = 0, j = 0;
    while (i < listA.size() && j < listB.size()) {
        if (listA[i] < listB[j]) {
            sortedList.push_back(listA[i]);
            i++;
        } else {
            sortedList.push_back(listB[j]);
            j++;
        }
    }
    while (i < listA.size()) {
        sortedList.push_back(listA[i]);
        i++;
    }
    while (j < listB.size()) {
        sortedList.push_back(listB[j]);
        j++;
    }
    return sortedList;
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
