// 520B - Two Buttons
// http://codeforces.com/problemset/problem/520/B
// Time Limit   : 2 seconds
// Memory Limit : 256 MB
#include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)(1e4 * 2 + 1);

// BFS: O(|E| + |V|)
// In this case, we have at <= 20000 vertices and up to 2 edges per vertex, so 2
// * 20000 = 40000 = |E| O(40000 + 20000) = small
int bfs(int n, int m) {
    vector<int> D(MAXN, -1);
    D[n] = 0;

    // This works for queue initialization of one single value, "s"
    queue<int> q({n});
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int x = u - 1, y = u * 2;
        if (x < 0 || y > MAXN) continue;

        // the initializer may be a braced-init-list
        // https://en.cppreference.com/w/cpp/language/range-for
        for (auto c : {x, y}) {
            if (D[c] == -1) D[c] = D[u] + 1, q.push(c);
        }
    }
    return D[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) << "\n";
}
