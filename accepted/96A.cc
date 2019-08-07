// 96A - Football
// http://codeforces.com/problemset/problem/96/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    if (s.find("0000000") != string::npos || s.find("1111111") != string::npos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
