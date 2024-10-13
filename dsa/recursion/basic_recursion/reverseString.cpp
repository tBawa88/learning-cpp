#include <iostream>
#include <string>

using namespace std;
string Reverse(string& S);
string Reverse2(string S);
string reverseHelper(string& S, int last, string rev = "");
int main() {
    string s;
    cin >> s;
    // cout << "Reverse(" << s << ") = " << Reverse(s) << endl;
    cout << "Reverse(" << s << ") = " << Reverse2(s) << endl;
    return 0;
}

string Reverse2(string S) {
    if (S.size() == 1)
        return S;

    int last = S.size() - 1;
    return S[last] + Reverse2(S.substr(0, last));
}

string Reverse(string& S) {
    return reverseHelper(S, S.size() - 1);
}

string reverseHelper(string& S, int last, string rev) {
    if (last == 0) {
        rev += S[last];
        return rev;
    }

    rev += S[last];
    return reverseHelper(S, last - 1, rev);
}
