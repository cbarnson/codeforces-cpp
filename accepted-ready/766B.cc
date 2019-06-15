// 766B - Mahmoud and a Triangle
// http://codeforces.com/problemset/problem/766/B

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// A degenerate triangle
bool is_degenerate(int a, int b, int c) {
    return a + b == c;
}

// A triangle that cannot exist
bool is_impossible(int a, int b, int c) {
    return a + b < c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vi A(n);
    for (auto &i : A) cin >> i;

    // Sort the list of numbers.  Why? By the Triangle Inequality Theorem, we
    // know that the sum of any two side lengths must be strictly greater than
    // the length of the third.  Obviously then, if we have 3 lengths, we only
    // really care to test that the sum of the two smallest sides are greater
    // than the third. https://en.wikipedia.org/wiki/Triangle_inequality
    sort(begin(A), end(A));

    FR(i, n - 2) {
        if (A[i] + A[i + 1] > A[i + 2]) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
