// 339A - Helpful Maths
// http://codeforces.com/problemset/problem/339/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    for_each(begin(s), end(s), [](char &c) { return c == '+' ? ' ' : c; });
    stringstream ss(s);
    vector<int> A;
    int x;
    while (ss >> x) {
        A.push_back(x);
    }
    sort(begin(A), end(A));
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i] << (i == (int)A.size() - 1 ? "\n" : "+");
    }
}
