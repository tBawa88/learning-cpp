#include <iostream>
#include <vector>

/**
 * Given an integer array, rotate it K times to the right
 */

// This solution produces TLE on the leetcode backend
// void rotate(std::vector<int>& arr, int k) {
//     if (k == 0 || arr.size() == 1) return;

//     while (k > 0) {
//         int last = arr[arr.size() - 1];  // get the last element
//         for (int i = arr.size() - 1; i > 0; i--) {
//             arr[i] = arr[i - 1];
//         }
//         arr[0] = last;
//         --k;
//     }
// }

// in -place solution using remainder to calculate the rotated position
void rotate1(std::vector<int>& arr, int k) {
    // first update K to find out the 'real' number of rotations we need
    // because if K > arr.size(), then the first arr.size() rotations are useless cuz they bring us to the same spot
    int length = arr.size();
    k = k % length;

    // if you observer the pattern, every element is being moved, k-places to the right for the final rotation
    // to do this operation, we need another aux array, from which we take out elements from their position and use them to update the original array
    // in current array's (i+k)%length position (which is the final postion of current element)
    // put aux arrays 'i' element
    std::vector<int> aux{arr};
    for (int i = 0; i < length; i++) {
        std::cout << "replacing: " << arr[i] << " to: " << aux[(i + k) % length] << std::endl;
        arr[(i + k) % length] = aux[i];
    }
}

void print(std::vector<int>& v) {
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    rotate1(arr, 3);
    print(arr);

    return 0;
}
