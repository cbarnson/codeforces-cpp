// 59A - Word
// http://codeforces.com/problemset/problem/59/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isupper(s[i])) {
            c++;
        }
    }
    if (c > (int)s.size() / 2) {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    }
    cout << s << endl;
}
