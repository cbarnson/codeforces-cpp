// 1097A - Gennady and a Card Game
// http://codeforces.com/problemset/problem/1097/A

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Notice that only EITHER the suit or face value has to match, and only one
    // of your five cards needs to match. Just look for any single character
    // match between the first line and second line.
    string a, b;
    cin >> a >> ws;
    getline(cin, b);
    for (auto i : a) {
        for (auto j : b) {
            if (i == j) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}
