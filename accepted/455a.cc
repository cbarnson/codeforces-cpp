// 455A - Boredom
// http://codeforces.com/problemset/problem/455/A
// Dynamic Programming

// DP solutions should be very formulaic and "simple" to think through once you
// get the hang of it.  It helps to practice some structure around your
// implementation to make coming up with a solution easier.  You will almost
// always have certain key elements in your dp-implementation:
// -----------------------------------------------------------------------------
// 1. memoization table, with values initialized to some special value like -1
//
// 2. recursive DP function, usually arguments will map directly with your
// memoization table (e.g. if your DP function is f(n), then your memoization
// table should be one-dimensional).  Try to avoid including any extra state
// information, or any modifications that would have to "undone" as in some
// recursive backtracking problems; YOU SHOULD BE ABLE TO DESCRIBE, IN PROSE,
// WHAT YOUR FUNCTION DOES/REPRESENTS IN ONE SENTENCE --> if you cannot do this,
// you shouldn't be writing code because you don't understand what you're doing!
//
// 2a. Base case for recursion
//
// 2b. Check for pre-computed result, returning immediately if exists
//
// 2c. Recurrence relation
//
// 2d. Assignment of computed result before control is returned to caller
// -----------------------------------------------------------------------------

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Array of the counts for given sequence values (i.e. A[i] is number of 'i'
// values in the sequence)
vector<ll> A;

// Memoization table, dp[i] is the max number of points possible if we are
// allowed to use integers up to i; where i <= 100000.  If dp[i] is -1, has not
// been computed.
vector<ll> dp;

// Returns the maximum number of points achievable from 1..n.
// f(0) = 0
// f(n) = max(f(n - 1), f(n - 2) + A[n] * n)
ll f(ll n) {
    if (n < 1) return 0;

    ll &x = dp[n];
    if (x != -1) return x;

    x = max(f(n - 1), f(n - 2) + A[n] * n);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    A.assign(100010, 0LL);
    dp.assign(100010, -1LL);
    dp[0] = 0LL;

    FR(i, n) {
        int x;
        cin >> x;
        A[x]++;
    }
    cout << f(100000LL) << endl;
}
