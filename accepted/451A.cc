// Problem #    : 451A
// Created on   : 2018-10-14 13:47:50
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 
typedef vector<int> vi;    

int main() {

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   
   int n, m;
   cin >> n >> m;

   n = m = min(n, m);
   if (n & 1)
      cout << "Akshat" << endl;
   else
      cout << "Malvika" << endl;


}
