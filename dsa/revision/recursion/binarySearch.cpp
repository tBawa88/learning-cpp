#include <string>
#include <vector>

int binarySearch(std::vector<int>& list, int key);
int search_helper(std::vector<int>& list, int key, int low, int high);

int binarySearch(std::vector<int>& list, int key) {
    return search_helper(list, key, 0, list.size() - 1);
}

int search_helper(std::vector<int>& list, int key, int low, int high) {
    if (high < low)
        return -1;

    int mid = (low + high) / 2;
    if (list[mid] == key)
        return mid;
    else if (key > list[mid])
        return search_helper(list, key, mid + 1, high);
    else
        return search_helper(list, key, low, mid - 1);
}
