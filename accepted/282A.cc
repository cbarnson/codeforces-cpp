// 282A - Bit++
// http://codeforces.com/problemset/problem/282/A
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, x = 0;
    cin >> n;
    while (n--) {
        string s; getline(cin >> ws, s);
        if (s.find('-') != string::npos) {
            x--;
        } else {
            x++;
        }
    }
    cout << x << endl;
}
