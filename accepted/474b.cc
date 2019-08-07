// 474B - Worms
// http://codeforces.com/problemset/problem/474/B
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, sz, x;
    // vector<int> A;
    // Normal arrays over push_back into vector
    // 93ms --> 78ms
    // 6200 KB --> 3908 KB

    // We given in question that the sum of all a_1, ..., a_n <= 10^6
    const int max_n = 1e6 + 10;
    int A[max_n];

    // Read in the pile sizes, and create an inverse lookup in A
    cin >> n;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> sz;
        while (sz--) A[k++] = i + 1;
    }
    cin >> m;
    while (m--) {
        cin >> x;
        cout << A[x - 1] << "\n";
    }
}
