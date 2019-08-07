// 459B - Pashmak and Flowers
// http://codeforces.com/problemset/problem/459/B
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

long long n_choose_k(long long n, long long k) {
    k = min(k, n - k);
    long long ans = 1;
    for (int i = 0; i < k; i++) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}

// time: 93 ms
// memory: 1.56 MB
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long mi, mx, mi_c, mx_c;
    vector<long long> A(n);
    for (auto &i : A) cin >> i;
    mi = *min_element(A.begin(), A.end());
    mx = *max_element(A.begin(), A.end());
    mi_c = count(A.begin(), A.end(), mi), mx_c = count(A.begin(), A.end(), mx);
    long long ans = (mi != mx ? mi_c * mx_c : n_choose_k(mi_c, 2));
    cout << abs(mx - mi) << " " << ans << "\n";
}
