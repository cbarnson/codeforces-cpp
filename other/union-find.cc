#include <bits/stdc++.h>
using namespace std;

// Union Find (Disjoint Set)
// Uses path compression and union by rank to give amortized time complexity:
// O(alpha(n)), where n is the number of nodes in the Union-find Disjoint-set.
class UnionFind {
  public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.assign(n, 0);
        iota(begin(parent), end(parent), 0);
        rank.assign(n, 0);
    }
    int find(int i) {
        return (parent[i] == i ? i : (parent[i] = find(parent[i])));
    }
    bool same(int i, int j) { return find(i) == find(j); }
    void merge(int i, int j) {
        if (!same(i, j)) {
            int x = find(i), y = find(j);
            if (rank[x] > rank[y])
                parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
