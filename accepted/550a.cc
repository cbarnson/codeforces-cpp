// 550A - Two Substrings
// http://codeforces.com/problemset/problem/550/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

// time: 31 ms
// memory: 300.00 KB
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;

    // Ugly code, but it does the job :)
    int a = 0, b = 0;
    int n = s.size();
    for (int i = 0; i < n - 1; i++) {
        if (!a && s[i] == 'A' && s[i + 1] == 'B') {
            a = 1, i++;
            continue;
        }
        if (a && s[i] == 'B' && s[i + 1] == 'A') {
            b = 1, i++;
            break;
        }
    }

    if (!a || !b) {
        a = 0, b = 0;
        for (int i = 0; i < n - 1; i++) {
            if (!b && s[i] == 'B' && s[i + 1] == 'A') {
                b = 1, i++;
                continue;
            }
            if (b && s[i] == 'A' && s[i + 1] == 'B') {
                a = 1, i++;
                continue;
            }
        }
    }
    cout << (a && b ? "YES\n" : "NO\n");

    // Too slow... times out
    // regex re("(AB.+BA|BA.+AB)");
    // if (regex_search(s, re)) {
    //     cout << "YES\n";
    // } else {
    //     cout << "NO\n";
    // }
}
