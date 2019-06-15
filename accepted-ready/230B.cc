// 230B - T-primes
// http://codeforces.com/problemset/problem/230/B

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// For most practical purposes, we can do up to 10^7 quickly; and it's always
// good practice to add a little bit to hardcoded dimensions for safety, hence
// the 10^7 + 10.
bitset<10000010> p;
ll sz;

void sieve(ll m) {
    // I habitually add one to 'sz', since we often call it like sieve(sqrt(N)),
    // the + 1 counter-acts any truncation that could introduce errors.
    sz = m + 1;
    p.set();
    p[0] = p[1] = 0;
    for (ll i = 2; i <= sz; i++) {
        if (p[i]) {
            for (ll j = i * i; j <= sz; j += i) {
                p[j] = 0;
            }
        }
    }
}

// sqrt(10^12) is 10^6, so we only need to compute primes, using the Sieve, up
// to 10^6
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // Call once, computing the primes up to sqrt(N), where N is the largest
    // possible input you could get.  Since our bounds go up to 10^12, we
    // compute the first 10^6 primes.
    sieve(1000000LL);

    int n;
    cin >> n;

    // We want to know if 'x' has exactly 3 positive divisors.  '1' is the first
    // positive divisor, and 'x' is the second.  The only way there is exactly
    // one more, is if 'x' is a perfect square, whose root is prime.
    FR(i, n) {
        ll x;
        cin >> x;
        ll r = sqrt(x);
        if (r * r == x && p[r]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
