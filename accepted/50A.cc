// 50A - Domino piling
// http://codeforces.com/problemset/problem/50/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    cout << (m + n == 2 ? 0 : (m * n) / 2) << endl;
}
