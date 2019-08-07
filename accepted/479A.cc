// 479A - Expression
// http://codeforces.com/problemset/problem/479/A
// Time Limit   :  seconds
// Memory Limit :  MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    int mx = -1;
    mx = max(mx, a[0] + a[1] + a[2]);
    mx = max(mx, a[0] * (a[1] + a[2]));
    mx = max(mx, (a[0] + a[1]) * a[2]);
    mx = max(mx, a[0] * a[1] * a[2]);
    cout << mx << '\n';
}
