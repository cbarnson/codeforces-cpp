// 4A - Watermelon
// http://codeforces.com/problemset/problem/4/A
// Time Limit   : 1 seconds
// Memory Limit : 64 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int w;
    cin >> w;
    cout << (w > 2 && ~w & 1 ? "YES" : "NO") << endl;
}
