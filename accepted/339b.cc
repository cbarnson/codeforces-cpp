// 339B - Xenia and Ringroad
// http://codeforces.com/problemset/problem/339/B
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, t = 0, p = 0;
    cin >> n >> m;
    while (m--) {
        long long x;
        cin >> x;
        x--;
        if (x < p)
            t += n - abs(p - x);
        else
            t += abs(x - p);
        p = x;
    }
    cout << t << '\n';
}
