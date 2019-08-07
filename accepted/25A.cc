// 25A - IQ test
// http://codeforces.com/problemset/problem/25/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, o = 0;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A) cin >> i;
    o = count_if(A.begin(), A.end(), [](int x) { return x & 1; });
    cout << find_if(A.begin(), A.end(),
                    [&](int x) { return (o > (n - o) ? ~x & 1 : x & 1); })
                - A.begin() + 1
         << '\n';
}
