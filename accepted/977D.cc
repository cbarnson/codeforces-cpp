// 977D - Divide by three, multiply by two
// http://codeforces.com/problemset/problem/977/D

// Model the problem as a graph, drawing directed edges from i -> j, such that
// i / 3 == j (i must be a multiple of 3) or i * 2 == j, for each ordered pair
// of nodes (i.e. numbers) i, j (where i != j).
#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

void dfs(int u, vi &vis, vector<vi> &g, vi &ts) {
    vis[u] = 1;
    for (auto &v : g[u]) {
        if (!vis[v]) {
            dfs(v, vis, g, ts);
        }
    }
    ts.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // 1 <= a[i] <= 10^18, for each i in [0, n-1], so need long long, which
    // gives room for integers up to (2^63)-1, which leaves us plenty of room
    // (even if we're careless doing our checks; since, at worst, 3 * 10^18 <
    // (2^63)-1)
    vector<ll> a(n);
    FR(i, n) { cin >> a[i]; }

    // Adjacency list representation of the possible paths from any number to
    // any other number.
    vector<vector<int>> g(n, vector<int>());

    // Guaranteed an answer exists, so just track in-degree, and later run
    // top-sort (dfs) from node with in-degree of 0 (i.e. the root).
    vi ind(n, 0);
    FR(i, n) {
        FR(j, n) {
            if (i == j) continue;

            // Important to check divisibility first, otherwise truncation will
            // introduce an error in our answer.
            if ((a[i] % 3LL == 0 && a[i] / 3LL == a[j]) || a[i] * 2LL == a[j]) {
                g[i].push_back(j);
                ind[j] += 1;
            }
        }
    }

    // Quick topological sort via dfs.  `n` is small, 2 <= n <= 100, so this
    // operation is negligible to our total time.
    vi ts;
    vi vis(n, 0);
    int src = 0;
    FR(i, n) {
        if (ind[i] == 0) src = i;
    }
    dfs(src, vis, g, ts);

    for (auto it = ts.rbegin(); it != ts.rend(); ++it) {
        cout << a[*it] << " ";
    }
    cout << endl;
}
