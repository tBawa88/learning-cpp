#include <iostream>
#include <string>
using namespace std;

#include "GCD.cpp"
#include "TOH.cpp"
#include "binarySearch.cpp"
#include "combinations.cpp"
#include "diceRolls.cpp"
#include "diceRolls2.cpp"
#include "diceSum.cpp"
#include "digital_root.cpp"
#include "finonacci.cpp"
#include "generateBinary.cpp"
#include "generateBinaryGray.cpp"
#include "listMnemonics.cpp"
#include "pallindrome.cpp"
#include "partitions.cpp"
#include "permutations.cpp"
#include "stringReverse.cpp"
#include "sublists1.cpp"
int main() {
    // int n;
    // cout << "Enter n to find nth term of fibonacci " << endl;
    // cin >> n;
    // cout << fibonacci(n) << endl;

    // string s;
    // cin >> s;
    // if (isPallindrome(s))
    //     cout << "String is Pallindrome\n";
    // else
    //     cout << "String is NOT Pallindrome\n";

    // vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    // int key;
    // cin >> key;
    // int i = binarySearch(list, key);
    // if (i == -1)
    //     cout << "Key not found \n";
    // else
    //     cout << "Key exists at index " << i << endl;

    // int x, y;
    // cin >> x >> y;
    // int g = gcd(x, y);
    // cout << "GCD of " << x << " and " << y << " is = " << g << endl;

    // int n;
    // cin >> n;
    // cout << "Digital root of " << n << "is = " << digitalRoot(n) << endl;

    // int n, r;
    // cout << "Enter n and r to find combination n Choose r\n";
    // cin >> n >> r;
    // cout << n << " C " << r << " = " << combinations(n, r) << endl;

    // string s;
    // cin >> s;
    // cout << reverseString(s);

    // int rods = 3;
    // moveRods(rods, 'A', 'C', 'B');

    // string s;
    // cin >> s;
    // ListPermutations(s);

    // ListMnemonics("234");

    // std::vector<char> list = {'A', 'B', 'C'};
    // ListSubsets(list);

    // int n;
    // cin >> n;
    // GenerateBinary(n);
    // GenerateGrayCode(n);

    // vector<int> list = {1, 2, 3, 4, 5};
    // int target = 5;
    // cout << "Number of partitions that have sum = " << target << " are = " << NumberOfPartitions(list, target) << endl;

    int numOfDice, targetSum;
    cin >> numOfDice >> targetSum;
    DiceSum(numOfDice, targetSum);
    // PrintDiceRolls(numOfDice);
    // DiceRolls(numOfDice);

    return 0;
}
