// 112A - Petya and Strings
// http://codeforces.com/problemset/problem/112/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    transform(begin(a), end(a), begin(a), ::tolower);
    transform(begin(b), end(b), begin(b), ::tolower);
    cout << a.compare(b) << endl;
}
