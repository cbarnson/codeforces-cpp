// Problem #    : 231a
// Created on   : 2018-09-27 23:06:22
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

   int a, b, c, cnt = 0;
   FR(i, n) {
      cin >> a >> b >> c;
      if (a + b + c > 1)
	 cnt++;
   }

   cout << cnt << endl;
   


}
