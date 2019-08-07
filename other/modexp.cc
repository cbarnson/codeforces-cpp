// Modular Exponentiation
// Compute x^n mod m
// Complexity: O(log n)
// https://en.wikipedia.org/wiki/Modular_exponentiation

#include <bits/stdc++.h>
using namespace std;

// The basic idea takes advantage of the fact that a^n * a^n = a^2n
// Also, applying our modulus rules, we know that
// (x + y) % m === ((x % m) + (y % m)) % m
// (x - y) % m === ((x % m) - (y % m)) % m
// (x * y) % m === ((x % m) * (y % m)) % m
// (x ^ n) % m === ((x % m) ^ n) % m
int modexp(int x, int n, int m) {
    if (n == 0) return 1;

    // If n is odd, x^n = x * x^(n-1),
    if (n & 1) return ((x % m) * modexp(x, n - 1, m)) % m;

    // If n is even, x^n = x^(n/2) * x^(n/2)
    // However, it is very important that we do not invoke modexp twice here,
    // reuse the result! This is how we get O(log n) complexity, by halving n
    // each time.
    int y = modexp(x, n / 2, m);
    return (y * y) % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
