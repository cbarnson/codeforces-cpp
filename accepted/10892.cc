// 10892 - LCM Cardinality
// https://uva.onlinejudge.org/external/108/10892.pdf
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Complexity is O(log n), n = min(a, b).  In this problem, n <= 2 * 10^9, so
// log(2 * 10^9) ~= 9.3..., negligible.
int lcm(int a, int b) {
    return a * (b / __gcd(a, b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n != 0) {
        vi d;

        // If you try to just lazy check divisors for 1..n, you will time out
        // (even on the sample input).  But there is no need, because you only
        // have to check up to sqrt(n).  Just be sure to add each divisor's
        // complement in the pair, unless that complement is the divisor itself
        // (don't add duplicates).
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                d.push_back(i);
                if (n / i != i) d.push_back(n / i);
            }
        }

        // Now you're free to check all lcm's across the divisors, but note d[i]
        // == d[j] is allowed (e.g. given n = 12, lcm(12, 12) == 12, which
        // counts towards total).
        int c = 0;
        for (int i = 0; i < d.size(); i++) {
            for (int j = i; j < d.size(); j++) {
                if (lcm(d[i], d[j]) == n) c++;
            }
        }
        cout << n << " " << c << "\n";
    }
}
