// 158A - Next Round
// http://codeforces.com/problemset/problem/158/A
// Time Limit   : 3 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &i : A) cin >> i;
    cout << count_if(begin(A), end(A), [&](int x) {
        return x > 0 && x >= A[k - 1];
    }) << endl;
}
