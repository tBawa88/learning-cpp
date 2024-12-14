#include <iostream>
#include <string>
using namespace std;

#include "GCD.cpp"
#include "binarySearch.cpp"
#include "finonacci.cpp"
#include "pallindrome.cpp"
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

    int x, y;
    cin >> x >> y;
    int g = gcd(x, y);
    cout << "GCD of " << x << " and " << y << " is = " << g << endl;

    return 0;
}
