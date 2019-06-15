#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Euclid's algorithm for Greatest Common Divisor
// https://en.wikipedia.org/wiki/Euclidean_algorithm
// Complexity: O(log n), where n = min(a, b)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Least Common Multiple
int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // You don't even have to write your own gcd if you're compiling with gcc,
    // there is a builtin function called __gcd(a, b), which can be handy since
    // it will work regardless of whether you're passing regular 'int' types or
    // 'long long' (types must match, of course).
    assert(gcd(123, 456) == __gcd(123LL, 456LL));
}
