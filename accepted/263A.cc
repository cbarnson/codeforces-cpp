// 263A - Beautiful Matrix
// http://codeforces.com/problemset/problem/263/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> x;
            if (x == 1) {
                cout << abs(2 - i) + abs(2 - j) << endl;
                return 0;
            }
        }
    }
}
