// 189A - Cut Ribbon
// http://codeforces.com/problemset/problem/189/A
// Dynamic Programming

// We are given 1 <= n, a, b, c <=4000, with n as the initial length, and a, b,
// c as valid cutting lengths.  We want to maximize the number of pieces, but
// each piece must be a valid cutting length.  DP is a good fit for this
// problem, because there are overlapping subproblems; starting from one end,
// cutting a length off, we then ask an identical question for the remaining
// length.
//
// Also important to note that we are guaranteed a solution for this problem, as
// given in the description.

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Contains the valid cutting lengths: a, b, and c
vi A(3);

// Memoization table, dp[i] is max number of pieces given initial length i
vi dp(4010, -1);

// Max number of pieces from length n.  Important to note, all valid entries in
// dp will be 1 less than the actual result.  We could have avoided this by
// introducing another special value like -2 for invalid, but it adds more lines
// of code than it saves.  Just report f(n) - 1 as the answer in main() for this
// problem.
int f(int n) {
    // Base case for success
    if (n == 0) return 1;

    // Base case for invalid, also catches when n < 0 so we don't have to
    // validate before recursing.
    if (n < *min_element(begin(A), end(A))) return 0;

    // Retrieve pre-computed value, if exists
    int &x = dp[n];
    if (x != -1) return x;

    // At each step, try cutting a, b, c from n.  If y is 0, it is invalid, and
    // the cut should not count when deciding whether to update x in the memo
    // table; otherwise add 1.
    for (auto &i : A) {
        int y = f(n - i);
        x = max(x, y + (y > 0 ? 1 : 0));
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (auto &i : A) cin >> i;
    cout << f(n) - 1 << endl;

    // Version 2
    // cout << f_v2(n, 0) << endl;
}

// -----------------------------------------------------------------------------
// Version 2 - (Inferior) Alternative
// Here's another way some people might choose to implement it, using two
// dimensions for our memoization table instead of just the one.  It is also
// accepted, but uses quite a bit more memory; stricter problem constraints
// might make this type of solution fail, but it can be a bit clearer because
// you don't have to adjust the final answer to get the correct result.  This is
// only feasible because of the <= 4000 bound.
// -----------------------------------------------------------------------------
// Memoization table, dp[i][j] = maximum number of pieces that can be cut for
// initial length i, and j is the number of cuts so far.
vector<vi> dp_v2(4010, vi(4010, -1));

// Max number of pieces from initial length n, and c cuts so far.
int f_v2(int n, int c) {
    if (n == 0) return c;
    if (n < *min_element(begin(A), end(A))) return 0;

    int &x = dp_v2[n][c];
    if (x != -1) return x;

    for (auto &i : A) {
        if (n >= i) x = max(x, f_v2(n - i, c + 1));
    }
    return x;
}