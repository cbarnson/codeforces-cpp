// 131A - cAPS lOCK
// http://codeforces.com/problemset/problem/131/A
// Time Limit   :  seconds
// Memory Limit :  MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    if (all_of(s.begin() + 1, s.end(), [](char c) { return isupper(c); })) {
        transform(s.begin(), s.end(), s.begin(),
                  [](char c) { return isupper(c) ? tolower(c) : toupper(c); });
    }
    cout << s << '\n';
}
