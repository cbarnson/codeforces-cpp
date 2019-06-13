// Problem #    : 268b
// Created on   : 2018-10-22 09:13:06
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n; cin >> n;

   int s = 0;
   for (int i = 1; i < n; i++) {
     s += (n - i) * i;
   }
   s += n;

   cout << s << endl;
   
}
