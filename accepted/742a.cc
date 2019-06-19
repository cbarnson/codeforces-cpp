// 742A - Arpa's hard exam and Mehrdad's naive cheat
// http://codeforces.com/problemset/problem/742/A

// While you might be able to just take your calculator, multiply 1378 * 1378 *
// ... notice the pattern in the last digit, and extrapolate for 'n', there is a
// better (dumber) solution, which takes much less thought.  Use modular
// exponentiation to quickly computer x^n mod 10 and report the answer.

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Computes x^n mod m
int modexp(int x, int n, int m) {
    if (n == 0) return 1;
    if (n & 1) return ((x % m) * modexp(x, n - 1, m)) % m;
    int y = modexp(x, n / 2, m);
    return (y * y) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    // mod by 10 to get the last digit
    cout << modexp(1378, n, 10) << endl;
}
