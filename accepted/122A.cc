// Problem #    : 122A
// Created on   : 2018-10-14 09:41:09
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vi A = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    int n;
    cin >> n;

    for (auto &x : A) {
        if (n % x == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
