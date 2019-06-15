// 507B - Amr and Pins
// http://codeforces.com/problemset/problem/507/B

// We need to keep our values as integer quantities, or else we inevitably lose
// precision and will fail on certain cases.  This can get quite ugly in some
// problems, here we take another approach: Binary search the answer!

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Radius, delta x and y
ll r, dx, dy;

// Validation function, where 'x' is the number of movements.  Return true if it
// is possible for 'x' steps, false otherwise.  Given 'r', the radius, we know
// we can move the center of the circle up to 2r each move.  With our Euclidean
// distance squared, the denominator also needs to be squared (i.e. (2r)^2 =
// 4r^2).  The number of steps, 'x', also needs to be squared.  Then we just
// check if the result gets us at least 'dist2' distance.
bool f(ll x) {
    ll dist2 = dx * dx + dy * dy;
    ll r2 = r * 2;
    r2 *= r2;
    return r2 * x * x >= dist2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll x, y, a, b;
    cin >> r >> x >> y >> a >> b;
    dx = x - a, dy = y - b;

    // We need to handle this case, or our starting point for 'lo' will be
    // wrong.
    if (x == a && y == b) {
        cout << 0 << endl;
        return 0;
    }

    // Binary search the answer:
    // This approach depends on a partitioning on two possible answers.  Here,
    // 'hi' represents the top segment (i.e. "yes, it is possible"), and 'lo'
    // represents the bottom segment (i.e. "no, it is not possible").
    //
    // It is good practice to avoid manually setting the inital values for 'lo'
    // and 'hi', I know for a fact that if 'lo' is 0 (i.e. 0 steps, which we
    // already covered for in our special case check above), then it is a
    // definite "no, it is not possible".  Start 'hi' at 1, and double it until
    // our validation function returns true; this becomes our inital upper
    // bound.
    ll lo = 0, hi = 1;
    while (!f(hi)) hi *= 2;

    // Another trick: don't try to nail down the exact case where you should
    // stop, it is too error prone and unnecessary.  Just give a little extra
    // room, then increment/decrement lo/hi after this loop to get your desired
    // partition point; in this case, we want the smallest 'x', for which f(x)
    // returns true, so we'll walk the 'lo' up until true, and that's our
    // answer.
    while (hi - lo > 5) {

        // IMPORTANT: always do --> lo + (hi - lo) / 2, NOT --> (lo + hi) / 2,
        // which is prone to overflow.
        ll mid = lo + (hi - lo) / 2;

        // Yes, ternary assignment works :)
        (f(mid) ? hi : lo) = mid;
    }
    while (!f(lo)) lo++;
    cout << lo << endl;
}
