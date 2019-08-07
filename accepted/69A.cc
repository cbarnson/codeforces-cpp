// 69A - Young Physicist
// http://codeforces.com/problemset/problem/69/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(3, 0);
    for (int i = 0; i < n; i++) {
        int x;
        for (int j = 0; j < 3; j++) {
            cin >> x;
            a[j] += x;
        }
    }

    if (all_of(a.begin(), a.end(), [](int x) { return x == 0; })) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
