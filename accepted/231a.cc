// 231A - Team
// http://codeforces.com/problemset/problem/231/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int t = 0;
    while (n--) {
        vector<int> A(3);
        for (auto &i : A) cin >> i;
        t += (count_if(begin(A), end(A), [](int x) {return x == 1;})) >= 2 ? 1 : 0;
    }
    cout << t << endl;
}
