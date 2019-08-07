// 281A - Word Capitalization
// http://codeforces.com/problemset/problem/281/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char c;
    int f = 0;
    while (cin >> c) {
        if (!f)
            cout << (char)toupper(c), f = 1;
        else
            cout << c;
    }
    cout << endl;
}
