// 492B - Vanya and Lanterns
// http://codeforces.com/problemset/problem/492/B
// Time Limit   : 1 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

// If you can help it, it's better to use 1e9 for readability, over 1000000000,
// since there's a chance you might mistype the number of 0's you need.  In this
// case, I made sure the cast works correctly before using this.  Scale all
// values by this quantity, so we don't need to worry about losing precision on
// double types.
const unsigned long long F = 1e9;

vector<unsigned long long> A;
unsigned long long n, l;
bool f(unsigned long long d) {
    unsigned long long x = A.front(), y = A.back();
    if (x > d || l - y > d) return false;
    for (int i = 0; i < A.size() - 1; i++) {
        x = A[i + 1], y = A[i];
        if (x - y > 2 * d) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l;
    l *= F;
    A.assign(n, 0);
    for (auto &i : A) {
        cin >> i;
        i *= F;
    }

    sort(A.begin(), A.end());

    // Use this trick to auto-set the upper bound of our binary search
    // partition, at a very small cost to the overall complexity.
    unsigned long long lo = 0, hi = 1 * F, mid;
    while (!f(hi)) hi *= 2;
    while (hi - lo > 5) {
        mid = lo + (hi - lo) / 2;
        (f(mid) ? hi : lo) = mid;
    }

    // top ---> hi is the "yes" portion,
    // lo  <--- bottom is the "no" portion.  Slide lo up to get our partition
    // point.
    while (!f(lo)) lo++;
    string ans = to_string(lo);
    ans.insert(ans.size() - 9, ".");
    cout << ans << '\n';
}
