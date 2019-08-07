// 580A - Kefa and First Steps
// http://codeforces.com/problemset/problem/580/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

// Trick here is just reading the problem carefully, at first it sounds like
// they want longest non-decreasing "subsequence", but no only a "subsegment",
// which we are told is a continuous fragment.  We don't even need to store
// anything, just process everything as you read it in.  Once you encounter a
// value strictly less than the last value, update your best, reset values, and
// continue.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, x, best = -1, counter = 0, last = 0;
    cin >> n;

    while (n--) {
        cin >> x;
        if (x < last) {
            best = max(best, counter);
            counter = 0;
        }
        counter++;
        last = x;
    }
    best = max(best, counter);
    cout << best << endl;
}
