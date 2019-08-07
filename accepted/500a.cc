// 500A - New Year Transportation
// http://codeforces.com/problemset/problem/500/A
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
void dfs(int s, vector<int> &vis) {
    vis[s] = 1;
    for (auto &i : g[s]) {
        if (!vis[i]) {
            dfs(i, vis);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    g.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        assert(i + x < n);
        g[i].push_back(i + x);
    }

    vector<int> vis(n, 0);
    dfs(0, vis);
    if (vis[t - 1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
