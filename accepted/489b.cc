// 489B - BerSU Ball
// http://codeforces.com/problemset/problem/489/B

#include <bits/stdc++.h>
#define FR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// https://en.wikipedia.org/wiki/Hopcroft–Karp_algorithm
// time complexity: O(E * sqrt(V))
class MaxMatching {
  public:
    static tuple<int, vi> max_matching(const vector<vi> &g) {
        int m = 0, n = g.size();

        for (auto &gg : g) {
            for (int u : gg) {
                m = max(m, u + 1);
            }
        }
        vi A(m, -1), D(n), matched(n);

        for (int i = 0, f = 0;; i += f, f = 0) {
            vi vis(n);
            bfs(g, matched, A, D);
            FR(u, n) if (!matched[u] && dfs(g, vis, matched, A, D, u)) f++;

            // final result condition
            if (!f) {
                return make_tuple(i, A);
            }
        }
    }

    static void bfs(const vector<vi> &g, vi &matched, vi &A, vi &D) {
        int n = g.size(), q = 0;
        fill(begin(D), end(D), -1);
        vi Q(n);
        FR(u, n) if (!matched[u]) Q[q++] = u, D[u] = 0;
        FR(i, q) {
            int u = Q[i];
            for (int v : g[u]) {
                int w = A[v];
                if (w >= 0 && D[w] < 0) D[w] = D[u] + 1, Q[q++] = w;
            }
        }
    }

    static bool dfs(const vector<vi> &g, vi &vis, vi &matched, vi &match, vi &D,
                    int u) {
        vis[u] = 1;
        for (int v : g[u]) {
            int w = match[v];
            if (w < 0 || (!vis[w] && D[w] == D[u] + 1 &&
                          dfs(g, vis, matched, match, D, w))) {
                match[v] = u;
                matched[u] = true;
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vi A(n);
    FR(i, n) cin >> A[i];

    int m;
    cin >> m;
    vi B(m);
    FR(i, m) cin >> B[i];

    vector<vi> g(101, vi());
    FR(i, n) {
        FR(j, m) {
            if (abs(A[i] - B[j]) < 2) {
                g[i].push_back(j + 100);
            }
        }
    }

    int t;
    tie(t, ignore) = MaxMatching::max_matching(g);
    cout << t << endl;
}
