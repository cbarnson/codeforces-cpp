// 1A - Theatre Square
// http://codeforces.com/problemset/problem/1/A
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, a;
    cin >> n >> m >> a;
    long long t = ((n / a) + (n % a ? 1 : 0)) * ((m / a) + (m % a ? 1 : 0));
    cout << t << endl;
}
