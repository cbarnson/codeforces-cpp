#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;        // max number nodes in graph
vi D;         // distance
vector<vi> G; // graph, adjacency list

void bfs(int src) {
    D.assign(n, -1);
    D[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : G[u]) {
            if (D[v] == -1) {
                D[v] = D[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
