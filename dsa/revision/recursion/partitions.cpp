#include <iostream>
#include <vector>

/**
 * Given a list of integers, find the number of sublists which add up to the target sum
 * --------------------------------------------------------------------------------------
 *
 * Solution1 : Explore all the possible sublists and increment the counter if a sublists matches the target sum
 *  - Exhaustive search using recursive backtracking
 *  - Inefficient becuase it will explore those sublists which we know are never going to add up to the target sum
 */

int NumberOfPartitions(std::vector<int>& list, int& targetSum);
void partitionsHelper(std::vector<int> list, int& targetSum, int& count, int& iterations, std::vector<int> chosen = {});
int listSum(std::vector<int>& list);

int NumberOfPartitions(std::vector<int>& list, int& targetSum) {
    int count = 0, iterations = 0;
    partitionsHelper(list, targetSum, count, iterations);
    std::cout << "Total iterations = " << iterations << std::endl;
    return count;
}

void partitionsHelper(std::vector<int> list, int& targetSum, int& count, int& iterations, std::vector<int> chosen) {
    ++iterations;
    if (list.empty()) {
        if (listSum(chosen) == targetSum)
            count++;
    } else {
        int first = list[0];
        list.erase(list.begin());

        chosen.push_back(first);
        // if adding a new element to the chosen sublist puts the current list sum over the target, don't bother exploring current sublist
        if (listSum(chosen) <= targetSum)
            partitionsHelper(list, targetSum, count, iterations, chosen);
        chosen.pop_back();
        partitionsHelper(list, targetSum, count, iterations, chosen);
    }
}

int listSum(std::vector<int>& list) {
    int sum = 0;
    for (int i : list)
        sum += i;
    return sum;
}
