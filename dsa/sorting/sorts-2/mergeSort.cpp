#include <vector>

using namespace std;

/**
 * Recursive approach for sorting:
 *  Sorting a list of size N is same as:
 *          Sorting a list of size 0 - N/2
 *          Sorting a list of size N/2 - N
 *          then merging them together
 *
 * Base case is the list of size 1; it's always sorted so return it directly
 */

vector<int> mergeSort(vector<int>& v) {
    if (v.size() < 2)
        return v;

    vector<int> listA(v.begin(), v.begin() + (v.size() / 2));
    vector<int> listB(v.begin() + (v.size() / 2), v.begin() + (v.size() - 1));

    return mergeTogether(mergeSort(listA), mergeSort(listB));
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
