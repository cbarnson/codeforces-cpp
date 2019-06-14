// 977B - Two-gram http://codeforces.com/problemset/problem/977/B

// Here all we have to do is step through all adjacent pairs of characters,
// keeping track of two-gram frequency, then report the pair of characters which
// occurs most frequent.
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  map<string, int> m;
  while (cin >> n >> s) {
    FR(i, n - 1) { m[s.substr(i, 2)] += 1; }
    string ans = s.substr(0, 2);
    for (auto& [k, v] : m) {
      if (m[ans] < v) ans = k;
    }
    cout << ans << endl;
  }
}
