#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int num_nodes; // total nodes in graph
vi visited;    // visited[i] = 1 for visited, else 0
vector<vi> G;  // graph, adjacency-list

// Recursive DFS helper
void dfs_helper(int u, vi &visited) {
    visited[u] = 1;
    for (auto &v : G[u]) {
        if (!visited[v]) {
               dfs_helper(v, visited);
        }
    }
}

// Main entrypoint for DFS from source node
void dfs(int src) {
    auto visited = vi(num_nodes, 0);
    dfs_helper(src, visited);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
