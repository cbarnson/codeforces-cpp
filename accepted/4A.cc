// Problem #    : 4A
// Created on   : 2018-09-27 20:55:34
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int w;
  cin >> w;

  cout << (w & 1 || (w <= 2) ? "NO" : "YES") << endl;
}
