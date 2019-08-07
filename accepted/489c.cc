// 489C - Given Length and Sum of Digits...
// http://codeforces.com/problemset/problem/489/C
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, s;
    cin >> m >> s;

    // Edge case, 0 <= s <= 900.
    if (s == 0) {
        cout << (m > 1 ? "-1 -1\n" : "0 0\n");
        return 0;
    }

    // Repeatedly subtract the largest possible single digit quantity from s,
    // resulting in { 9, 9, ... X } with 'X' being some value between 1 and 9.
    vector<int> A;
    while (s) A.push_back(min(9, s)), s -= min(9, s);
    vector<int> B(A);
    if (A.size() > m) {
        cout << "-1 -1\n";
        return 0;
    }
    // Min
    // Smallest possible will have a '1' in the most significant position, if
    // there is room left in our capacity 'm' digits, take 1 off the back,
    // append 0's, then re-add the 1.  This, reversed, is the smallest possible
    // number with 'm' digits, and digit-sum 's'
    while (A.size() < m) {
        A[A.size() - 1] -= 1;
        while (A.size() < m - 1) A.push_back(0);
        A.push_back(1);
    }
    for_each(rbegin(A), rend(A), [](auto a) { cout << a; }), cout << " ";

    // Max
    // Already in descending order, just need to append 0's if fewer than 'm'
    // elements in B
    while (B.size() < m) B.push_back(0);
    for_each(begin(B), end(B), [](auto b) { cout << b; }), cout << "\n";
}
