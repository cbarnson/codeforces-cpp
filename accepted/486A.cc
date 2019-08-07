// 486A - Calculating Function
// http://codeforces.com/problemset/problem/486/A
// Time Limit   :  seconds
// Memory Limit :  MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Pattern is:
    //      |  0 |  1 |  2 |  3 |  4 |  5 |  6 | ...
    // f(n) |  0 | -1 |  1 | -2 |  2 | -3 |  3 | ...
    long long n, ans;
    cin >> n;
    ans = ((n + 1LL) / 2LL) * (n & 1LL ? -1LL : 1LL);
    cout << ans << endl;
}
