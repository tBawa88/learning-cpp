#include <vector>

class Solution {
   public:
    bool check(std::vector<int>& arr) {
        int unsortedIdx = -1;
        int comparisonIdx;
        int size = arr.size();
        // first loop to find the unsortedIndex
        for (int i = 1; i < size; i++) {
            if (arr[i] < arr[i - 1]) {
                unsortedIdx = i;
                break;
            }
        }
        // this means that array was sorted and has no rotation
        if (unsortedIdx == -1) return true;

        // now we must do another pass, checking the sorted-ness,
        comparisonIdx = unsortedIdx + 1;

        for (int x = 0; x < size - 1; x++) {
            if (arr[(unsortedIdx) % size] > arr[(comparisonIdx) % size]) {
                return false;
            }
            ++unsortedIdx;
            ++comparisonIdx;
        }
        return true;
    }
};
