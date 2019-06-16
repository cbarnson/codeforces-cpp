// 513A - Game
// http://codeforces.com/problemset/problem/513/A
// Dynamic Programming, Minimax, Game Theory

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int k1, k2;

// Given that inputs 1 <= n1, n2, k1, k2 <= 50. dp[n1][n2][fl] is the score of
// the first player (0 or 1, where 1 means first player wins) for n1, n2 balls
// for first and second players, respectively, and fl = 1 for first player's
// turn, fl = 0 for second player's turn.
int dp[55][55][2];

// -----------------------------------------------------------------------------
// Minimax - Game Theory
// -----------------------------------------------------------------------------
// Returns the score of the game, if both players play optimally, where n1 is
// balls of first player, n2 is balls of second player, and fl is 1 for first
// player's turn, fl is 0 for second player's turn.
int minimax(int n1, int n2, int fl) {

    // first player turn and n1 is 0 --> first player loses
    if (fl && n1 == 0) return 0;

    // second player turn and n2 is 0 --> first player wins
    if (!fl && n2 == 0) return 1;

    // Retrieve pre-computed result, if exists
    int &x = dp[n1][n2][fl];
    if (x != -1) return x;

    // Depending on whose turn it is, find the "best" possible outcome (max if
    // first player turn, min if second player turn), try options from 1 to k,
    // update x
    int k = (fl ? k1 : k2);
    for (int i = 1; i <= k; i++) {
        if (fl && n1 - i >= 0) {
            x = max(x == -1 ? 0 : x, minimax(n1 - i, n2, !fl));
        } else if (!fl && n2 - i >= 0) {
            x = min(x == -1 ? 1 : x, minimax(n1, n2 - i, !fl));
        }
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));

    cout << (minimax(n1, n2, 1) ? "First" : "Second") << endl;
}
