// 318A - Even Odds
// http://codeforces.com/problemset/problem/318/A
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // given n, k in [1, 10^12]
    // give the number in the kth position according to problem
    long long n, k, o, e;
    cin >> n >> k;
    o = (n + 1) / 2, e = n / 2;
    if (k <= o) {
        cout << k * 2 - 1 << '\n';
    } else {
        cout << (k - o) * 2 << '\n';
    }
}
