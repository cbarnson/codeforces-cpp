// 118A - String Task
// http://codeforces.com/problemset/problem/118/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, v = "aoyeui", ans = "";
    cin >> s;
    transform(begin(s), end(s), begin(s), ::tolower);
    for (int i = 0; i < s.size(); i++) {
        if (v.find(s[i]) == string::npos) {
            ans += string() + "." + s[i];
        }
    }
    cout << ans << endl;
}
