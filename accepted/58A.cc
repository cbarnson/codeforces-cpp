// 58A - Chat room
// http://codeforces.com/problemset/problem/58/A
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, h = "hello";
    cin >> s;
    int i = 0;
    for (int j = 0; j < (int)s.size(); j++) {
        if (s[j] == h[i]) {
            i++;
            if (i == h.size()) break;
        }
    }
    cout << (i == h.size() ? "YES\n" : "NO\n");
}
