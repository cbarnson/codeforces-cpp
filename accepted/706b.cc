// Problem #    : 706b
// Created on   : 2018-10-27 10:51:17
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n;
   cin >> n;

   vi P(n);
   for (auto &x : P) cin >> x;
   int m;
   cin >> m;

   sort(begin(P), end(P));
   FR(i, m) {
      int x; cin >> x;
      auto j = upper_bound(begin(P), end(P), x) - begin(P);
      cout << j << endl;
   }
   


}
