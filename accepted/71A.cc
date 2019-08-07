// 71A - Way Too Long Words
// http://codeforces.com/problemset/problem/71/A
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if ((int)s.length() > 10) {
            cout << s.front() << s.length() - 2 << s.back() << endl;
        } else {
            cout << s << endl;
        }
    }
}
